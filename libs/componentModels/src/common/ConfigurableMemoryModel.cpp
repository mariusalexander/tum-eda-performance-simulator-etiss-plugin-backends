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

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cassert>

namespace
{

template <typename T, typename U>
inline std::ostream&
operator<<(std::ostream& s, std::pair<T, U> const& t)
{
    return s << '(' << t.first << ", " << t.second << ')';
}

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

template<typename K, typename V, typename... R>
std::ostream& operator<<(std::ostream& s, std::map<K, V, R...> const& t)
{
    logIter(s, t.begin(), t.end(), "{\n ", "\n}\n", ",\n ");
    return s;
}

/**
 * @brief
 */
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

inline bool
isInCache(cmm::CacheBlock& block, uint64_t tag)
{
    for (cmm::CacheEntry const& entry : block)
    {
        if (entry.tag == tag && entry.isValid())
        {
            // TODO: update cache entries (e.g. access time)
            return true;
        }
    }
    return false;
}

inline cmm::CacheEntry*
findInvalidEntry(cmm::CacheBlock& block)
{
    // replace invalid entry
    for (cmm::CacheEntry& entry : block)
    {
        if (!entry.isValid())
        {
            return &entry;
        }
    }
    return nullptr;
}

} // namespace

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

bool
cmm::Cache::applyConfig(etiss::Configuration& config,
                        std::string const& configPath)
{
    bool success = true;
    size_t m_nblocks, m_nways, m_blockSize;
    success &= loadFromConfig(config, configPath + ".nblocks", m_nblocks);
    success &= loadFromConfig(config, configPath + ".nways", m_nways);
    success &= loadFromConfig(config, configPath + ".delay.cacheMiss", m_cacheMissDelay);
    success &= loadFromConfig(config, configPath + ".delay.cacheHit", m_cacheHitDelay);

    if (!success)
    {
        std::cout << "ERROR: Cache specifications are invalid!" << std::endl;
        return false;
    }

    // not critical
    loadFromConfig(config, configPath + ".blockSize", m_blockSize, (size_t)1);

    // allocate tag memory
    m_tagCache.resize(m_nways, m_nblocks, m_blockSize);

    // evict strategy
    uint8_t shift_state = 0;
    const size_t ways = m_tagCache.ways() - 1;

    auto lfsr = [shift_state, ways](cmm::CacheBlock& block) mutable -> cmm::CacheEntry* {
        uint8_t shift_in = ~(((shift_state & 0x80) >> 7) ^
                             ((shift_state & 0x08) >> 3) ^
                             ((shift_state & 0x04) >> 2) ^
                             ((shift_state & 0x02) >> 1));
        shift_state = (shift_state << 1) | shift_in;
        return block.begin() + (shift_state & ways);
    };
    m_evictStrategy = lfsr;

    return success;
}

cmm::Cache::Cache(std::string name) :
    m_name(std::move(name))
{ }

cmm::Cache::~Cache()
{
    uint total = t_hits + t_misses;
    if (total == 0) return;

    std::cout << m_name << " Cache Performance:" "\n "
              << t_hits      << " cache hits ("
              << std::setprecision(4) << (t_hits * 100.0) / total         << "%)" "\n "
              << t_evictions << " evictions ("
              << std::setprecision(4) << (t_evictions * 100.0) / t_misses << "%) of "
              << t_misses    << " cache misses ("
              << std::setprecision(4) << (t_misses * 100.0) / total       << "%)"
              << std::endl;
}

bool
cmm::Cache::fetch(uint64_t addr, int& delay)
{
    uint64_t tag   = m_tagCache.getTag(addr);
    uint64_t index = m_tagCache.getBlockIndex(addr);

    cmm::CacheBlock block = m_tagCache.getBlock(index);

    if (isInCache(block, tag))
    {
        // Cache hit
        delay += m_cacheHitDelay;
        t_hits++;
        return true;
    }

    // cache miss
    delay += m_cacheMissDelay;
    t_misses++;

    // replace entry
    cmm::CacheEntry* entry = findInvalidEntry(block);

    if (!entry)
    {
        t_evictions++;
        entry = m_evictStrategy(block);
    }

    entry->tag = tag;
    entry->setFlag(cmm::Invalid, false);

    return false;
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

    for (size_t idx = 0; idx < m_cacheCount; ++idx)
    {
        // access cache
        cmm::Cache& cache = m_caches[idx];

        bool hit = cache.fetch(addr, delay);
        if (hit) break;
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

        registerCache(config, cacheName);
    }

    // no cache added -> use default constructed memory level
    if (m_cacheCount == 0)
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

void
ConfigurableMemoryModel::registerCache(etiss::Configuration& config,
                                       std::string const& cacheName)
{
    std::cout << "Registering cache '" << cacheName << "'..." << std::endl;

    if (m_cacheCount >= m_caches.size())
    {
        throw std::runtime_error("ConfigurableMemoryModel::m_levels is out of memory");
    }

    std::string configPath = "plugin.perfEst.memory." + cacheName;

    // setup cache
    cmm::Cache cache{cacheName};
    bool success = cache.applyConfig(config, configPath);
    if (!success) return;

    // append cache
    m_caches[m_cacheCount] = std::move(cache);
    m_cacheCount++;
}
