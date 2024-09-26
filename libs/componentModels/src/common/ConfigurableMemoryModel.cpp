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

} // namespace

bool
ConfigurableCache::applyConfig(etiss::Configuration& config,
                               std::string const& configPath)
{
    bool success = true;
    success &= loadFromConfig(config, configPath + ".nblocks", m_nblocks);
    success &= loadFromConfig(config, configPath + ".nways", m_nways);
    success &= loadFromConfig(config, configPath + ".delay.notCachable", m_delay.notCachable);
    success &= loadFromConfig(config, configPath + ".delay.cacheMiss", m_delay.cacheMiss);
    success &= loadFromConfig(config, configPath + ".delay.cacheHit", m_delay.cacheHit);

    if (!success)
    {
        std::cout << "ERROR: Cache specifications are invalid!" << std::endl;
        return false;
    }

    // not critical
    loadFromConfig(config, configPath + ".blockSize", m_blockSize, (size_t)1);
    loadFromConfig(config, configPath + ".addrspace.lower", m_addrSpace.lower, (uint64_t)0x0);
    loadFromConfig(config, configPath + ".addrspace.upper", m_addrSpace.upper, std::numeric_limits<uint64_t>::max());
    loadFromConfig(config, configPath + ".delay.notCachable", m_delay.notCachable);
    loadFromConfig(config, configPath + ".delay.cacheReplacement", m_delay.cacheReplacement);

    if (m_addrSpace.lower > m_addrSpace.upper)
    {
        std::cout << "ERROR: invalid address space: 0x" << std::hex
                  << m_addrSpace.lower << " - 0x" << m_addrSpace.upper << std::dec
                  << std::endl;
        return false;
    }

    m_offsetBits = 2 + // offset for byte index
                   ceil(log2(m_blockSize)); // offset for word index
    m_indexBits = ceil(log2(m_nblocks));

    std::cout << "Offset-bits: " << m_offsetBits << ", Index-bits:" << m_indexBits << std::endl;

    // allocate tag memory
    size_t size = m_nblocks * m_nways;
    m_tagCache.resize(size);

    return success;
}

ConfigurableCache::ConfigurableCache(std::string name) :
    m_name(std::move(name))
{ }


bool
ConfigurableCache::fetch(uint64_t addr, int& delay)
{
    if (!m_addrSpace.isCachable(addr))
    {
        // not cachable
        delay += m_delay.notCachable;
        return false;
    }
    uint64_t tag   =  addr >> (m_offsetBits + m_indexBits);
    uint64_t index = (addr >> m_offsetBits) & ~(tag << m_indexBits);

    assert(index < m_nblocks);

    size_t baseIdx  = index * m_nways;

    for(size_t way_i = 0; way_i < m_nways; ++way_i)
    {
        size_t srcIndex = baseIdx + way_i;
        if (m_tagCache[srcIndex].tag == tag &&
            m_tagCache[srcIndex].isValid())
        {
            // Cache hit
            delay += m_delay.cacheHit;
            // TODO: update cache entries (e.g. access time)
            return true;
        }
    }

    // cache miss
    delay += m_delay.cacheMiss;

    // cache replacement
    delay += m_delay.cacheReplacement;

    size_t idx = std::numeric_limits<size_t>::max();

    for(size_t way_i = 0; way_i < m_nways; ++way_i)
    {
        size_t srcIndex = baseIdx + way_i;
        if (!m_tagCache[srcIndex].isValid())
        {
            idx = srcIndex;
            break;
        }
    }

    // force eviction
    if (idx == std::numeric_limits<size_t>::max())
    {
        static uint8_t shift_state = 0;
        uint8_t shift_in = ~(((shift_state & 0x80) >> 7) ^ ((shift_state & 0x08) >> 3) ^ ((shift_state & 0x04) >> 2) ^ ((shift_state & 0x02) >> 1));
        shift_state = (shift_state << 1) | shift_in;
        idx = baseIdx + (shift_state & (m_nways - 1));
    }

    m_tagCache[idx].tag = tag;
    m_tagCache[idx].flags &= ~Invalid;
    return false;
}

ConfigurableMemoryModel::ConfigurableMemoryModel(PerformanceModel* parent_) :
    ResourceModel("ConfigurableMemoryModel", parent_)
{ }

int
ConfigurableMemoryModel::getDelay()
{
    int delay = 0;

    for (size_t idx = 0; idx < m_cacheCount; ++idx)
    {
        // access cache
        ConfigurableCache& cache = m_caches[idx];

        bool hit = cache.fetch(addr_ptr[getInstrIndex()], delay);
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
    ConfigurableCache cache{cacheName};
    bool success = cache.applyConfig(config, configPath);
    if (!success) return;

    // append cache
    m_caches[m_cacheCount] = std::move(cache);
    m_cacheCount++;
}

