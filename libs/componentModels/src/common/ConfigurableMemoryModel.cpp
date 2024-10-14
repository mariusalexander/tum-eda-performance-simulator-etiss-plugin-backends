/*
 * Copyright 2022 Chair of EDA, Technical University of Munich
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	 http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "models/common/ConfigurableMemoryModel.h"

#include "etiss/Misc.h"

#include <string>
#include <cmath>
#include <cassert>

#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <fstream>

// define to enable/disable logging of cache performance statisitcs
#define OUTPUT_STATISTICS

#ifdef OUTPUT_STATISTICS
#define STATISTICS_ONLY(STATEMENT) STATEMENT
#else
#define STATISTICS_ONLY(STATEMENT) STATEMENT
#endif

namespace
{

/// logs std::pair to console (required for std::map)
template <typename T, typename U>
inline std::ostream&
operator<<(std::ostream& s, std::pair<T, U> const& t)
{
    return s << '(' << t.first << ", " << t.second << ')';
}

/// helper method to log iteator ranges to console
template<typename Iter>
void logIter(std::ostream& s,
             Iter a, Iter b,
             char const* pre,
             char const* suf,
             char const* sep = ", ") noexcept
{
    s << pre;
    if (a != b) // not empty
    {
        Iter b_1 = std::next(a, std::distance(a, b)-1);
        // log until nth - 1 element
        std::for_each(a, b_1, [&s, sep](auto const& val){
            s << val;
            s << sep;
        });
        // log nth element
        s << *b_1;
    }
    s << suf;
}

/// logs std::map to console
template<typename K, typename V, typename... R>
std::ostream& operator<<(std::ostream& s, std::map<K, V, R...> const& t)
{
    logIter(s, t.begin(), t.end(), "{\n ", "\n}\n", ",\n ");
    return s;
}

template<typename T>
bool loadFromConfig(etiss::Configuration& config, std::string const& path, T& value, T const& default_ = {})
{
    value = config.get<size_t>(path, T{});
    if (value == T{})
    {
        std::cout << "WARNING: configuration '" << path
                  << "' not defined!" << std::endl;
        value = default_;
        return false;
    }
    return true;
}

} // namespace

namespace eviction_strategy
{

inline auto lfsr(const cmm::TagMemory& tagMemory)
{
    // evict strategy
    uint8_t shift_state = 0;
    const size_t ways = tagMemory.ways() - 1;

    return [shift_state, ways](cmm::CacheBlock& block) mutable -> cmm::CacheEntry* {
        uint8_t shift_in = ~(((shift_state & 0x80) >> 7) ^
                             ((shift_state & 0x08) >> 3) ^
                             ((shift_state & 0x04) >> 2) ^
                             ((shift_state & 0x02) >> 1));
        shift_state = (shift_state << 1) | shift_in;
        return block.begin() + (shift_state & ways);
    };

}

} // namespace eviction_strategy

namespace is_valid_strategy
{

inline auto default_()
{
    return [](cmm::CacheEntry& entry){
        return entry.isValid();
    };
}

} // namespace eviction_strategy

void
cmm::TagMemory::resize(size_type ways, size_type blocks, size_type blockSize)
{
    constexpr size_t wordSize = 4; // in bytes

    m_ways = ways;
    m_blocks = blocks;
    m_blockSize = blockSize;

    m_data.resize(ways * blocks);

    m_offsetBits = ceil(log2(wordSize)) +   // offset to index byte in a word
                   ceil(log2(m_blockSize)); // offset to index word in block
    m_indexBits  = ceil(log2(m_blocks));    // index for blocks

    std::cout << "INFO: "
              << "allocated tag memory: " << blocks
              << " lines x " << ways << " ways"
              << " (index-bits: " << m_indexBits
              << ", offset-bits: " << m_offsetBits <<  ")" << std::endl;
}

cmm::Cache::Cache(std::string name,
                  TagMemory memory,
                  CacheDelays delays,
                  IsValidStrategy isValidStrategy,
                  EvictionStrategy evictionStrategy) :
    m_name(std::move(name)),
    m_delays(std::move(delays)),
    m_tagMemory(std::move(memory)),
    m_isValidStrategy(std::move(isValidStrategy)),
    m_evictStrategy(std::move(evictionStrategy))
{
    assert(m_isValidStrategy);
    assert(m_evictStrategy);
}

cmm::Cache::~Cache()
{
#ifdef OUTPUT_STATISTICS
    // output statistics
    constexpr unsigned width = 6, precision = 4;
    unsigned total = t_hits + t_misses;

    if (total == 0) return;

    // basic statistics
    std::cout << "\n"
              << m_name << " Cache Performance:" "\n "
              << std::setw(width) << std::right <<  t_hits                          << " cache hits ("
              << std::setprecision(precision)   << (t_hits * 100.0) / total         << "%) and" "\n "
              << std::setw(width) << std::right <<  t_misses                        << " cache misses ("
              << std::setprecision(precision)   << (t_misses * 100.0) / total       << "%) with" "\n "
              << std::setw(width) << std::right <<  t_evictions                     << " evictions ("
              << std::setprecision(precision)   << (t_evictions * 100.0) / t_misses << "%)"
              << std::endl;

    // find path to exe
    char cwd[256];
    size_t len = readlink("/proc/self/exe", cwd, sizeof(cwd));
    if (len < 0 || len > sizeof(cwd)) return;

    std::string filePath;
    // find directory
    auto rbegin = std::make_reverse_iterator(cwd + len);
    auto rend = std::make_reverse_iterator(cwd);
    auto directory = std::find(rbegin, rend, '/');
    if (directory == rend) return;

    std::copy(cwd, directory.base(), std::back_inserter(filePath));
    filePath += "histogram-" + name() + ".csv";

    std::cout << "creating cache histogram at " << filePath << std::endl;

    // detailed cache statistics
    std::ofstream fs;
    fs.open(filePath, std::ios::out);

    if (!fs.is_open()) return;

    // header
    fs << "index," "ways-used," "hits," "evictions\n";

    // data
    for (size_t idx = 0; idx < m_tagMemory.blocks(); idx++)
    {
        // accumulate statistics of all ways
        uint32_t hits = 0, evictions = 0, waysUsed = 0;
        for (size_t way = 0; way < m_tagMemory.ways(); way++)
        {
            auto* entry = (m_tagMemory.getBlock(idx).begin() + way);
            if (entry->t_hits > 0) waysUsed  += 1;

            hits  += entry->t_hits;
            evictions += entry->t_evictions;
        }
        fs << std::hex << idx << std::dec << "," << waysUsed << "," << hits << "," << evictions << "\n";
    }

    fs << std::endl;
    fs.close();
#endif
}

bool
cmm::Cache::fetch(uint64_t addr, int& delay)
{
    const uint64_t tag   = m_tagMemory.getTag(addr);
    const uint64_t index = m_tagMemory.getBlockIndex(addr);

    CacheBlock block = m_tagMemory.getBlock(index);

    CacheEntry* entry = block.findEntry(tag);

    const bool hit = !!entry;
    if (hit) // cache hit
    {
        delay += m_delays.hit;
        STATISTICS_ONLY(t_hits++);

        // check if entry is valid
        if (m_isValidStrategy(*entry))
        {
            STATISTICS_ONLY(entry->t_hits++);

            update(block, *entry);
            return hit;
        }

        // TODO: entry requires writeback
        writeback(*entry);
    }
    else // cache miss
    {        
        delay += m_delays.miss;
        STATISTICS_ONLY(t_misses++);

        // find entry to replace
        entry = block.findInvalidEntry();
        if (!entry)
        {
            // evict valid entry
            entry = m_evictStrategy(block);

            STATISTICS_ONLY(t_evictions++);
            STATISTICS_ONLY(entry->t_evictions++);
        }
    }

    assert(entry);

    // replace entry
    replace(block, *entry, tag);
    update(block, *entry);
    return hit;
}

void
cmm::Cache::update(CacheBlock block,
                   CacheEntry& entry)
{
    // TODO: update cache entry/block? (e.g. access time)
}

void
cmm::Cache::replace(CacheBlock block,
                    CacheEntry& entry,
                    uint64_t tag)
{
    // replace entry
    entry.tag = tag;
    entry.setFlag(Invalid, false);
}

ConfigurableMemoryModel::ConfigurableMemoryModel(PerformanceModel* parent_) :
    ResourceModel("ConfigurableMemoryModel", parent_)
{ }

int
ConfigurableMemoryModel::getDelay()
{
    uint64_t addr = addr_ptr[getInstrIndex()];

    // not cachable
    if (!m_addrSpace.isCachable(addr))
    {
        return m_notCachableDelay;
    }

    int delay = 0;

    // iterate through all caches
    for (cmm::Cache& cache : m_caches)
    {
        bool hit = cache.fetch(addr, delay);
        if (hit) break; // exit on hit
    }
    return delay;
}

void
ConfigurableMemoryModel::applyConfig(etiss::Configuration& config)
{
    // separator used to parase string list in config file
    constexpr char SEPARATOR = ' ';

    std::cout << "Memory config: " << config.config() << std::endl;

    // parse list of memory levels
    std::string levels = config.get<std::string>("plugin.perfEst.memory.layout", {});

    auto iter = levels.begin();
    auto end = levels.end();

    while (iter != end)
    {
        auto substrEnd = std::find(iter, end, SEPARATOR);
        if (iter == substrEnd) break;

        // create substring until separator
        std::string cacheName{iter, substrEnd};

        iter = substrEnd;

        // iter points to separator -> advance
        while (iter != end && *iter == SEPARATOR) iter++;

        if (!registerCache(config, cacheName))
        {
            throw std::runtime_error("Failed to register cache '" + cacheName + "'");
        }
    }

    // no cache added -> use default constructed memory level
    if (m_caches.empty())
    {
        std::cout << "WARNING: no caches were registered!" << std::endl;
    }

    loadFromConfig(config, "plugin.perfEst.memory.addrspace.lower", m_addrSpace.lower, (uint64_t)0x0);
    loadFromConfig(config, "plugin.perfEst.memory.addrspace.upper", m_addrSpace.upper, std::numeric_limits<uint64_t>::max());
    loadFromConfig(config, "plugin.perfEst.memory.delay.notCachable", m_notCachableDelay);

    if (m_addrSpace.lower > m_addrSpace.upper)
    {
        std::stringstream ss;
        ss << "invalid address space: 0x" << std::hex
           << m_addrSpace.lower << " - 0x" << m_addrSpace.upper;

        throw std::runtime_error(ss.str());
    }

    std::cout << std::endl;
}

bool
ConfigurableMemoryModel::registerCache(etiss::Configuration& config,
                                       std::string const& cacheName)
{
    std::cout << "Registering cache '" << cacheName << "'..." << std::endl;

    std::string configPath = "plugin.perfEst.memory." + cacheName;

    size_t nblocks = 0, nways = 0, blockSize = 0;

    bool success = true;
    // not critical
    loadFromConfig(config, configPath + ".blockSize", blockSize, (size_t)1);
    success &= loadFromConfig(config, configPath + ".nblocks", nblocks);
    success &= loadFromConfig(config, configPath + ".nways", nways);

    cmm::CacheDelays delays;
    success &= loadFromConfig(config, configPath + ".delay.cacheMiss", delays.miss);
    success &= loadFromConfig(config, configPath + ".delay.cacheHit", delays.hit);

    if (!success)
    {
        std::cout << "ERROR: Cache specifications are invalid!" << std::endl;
        return false;
    }

    // allocate tag memory
    cmm::TagMemory tagMemory;
    tagMemory.resize(nways, nblocks, blockSize);

    // strategies
    auto evictionStrat = eviction_strategy::lfsr(tagMemory);
    auto isValidStrat  = is_valid_strategy::default_();

    // append cache
    m_caches.emplace_back(cacheName,
                          std::move(tagMemory),
                          std::move(delays),
                          std::move(isValidStrat),
                          std::move(evictionStrat));
    return true;
}
