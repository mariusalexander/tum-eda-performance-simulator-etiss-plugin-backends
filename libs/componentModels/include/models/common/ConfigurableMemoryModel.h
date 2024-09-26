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

#ifndef CONFIGURABLE_MEMORY_MODEL_H
#define CONFIGURABLE_MEMORY_MODEL_H

#include "PerformanceModel.h"

#include <vector>
#include <functional>

/// configurable memory model
namespace cmm
{

/// Status flags of a cache entry
enum StatusFlag : unsigned
{
    NoFlag = 0,
    Invalid = 1 << 0,
    // TODO: Dirty Flag? Coherency Flags?
};
using StatusFlags = unsigned;

/// Cache entry
struct CacheEntry
{
    uint64_t tag = 0x0;
    StatusFlags flags = Invalid;

    constexpr inline bool isValid() const
    {
        return !(flags & Invalid);
    }

    constexpr inline void setFlag(StatusFlag flag, bool enable = true)
    {
        enable ? flags |=  flag :
                 flags &= ~flag;
    }
};

struct CacheBlock
{
    /// start of range
    CacheEntry* begin_{};
    /// end of range
    CacheEntry* end_{};

    CacheEntry* begin() { return begin_; }
    CacheEntry* end() { return end_; }
};

class TagMemory
{
    using container_type = std::vector<CacheEntry>;

public:
    using value_type = typename container_type::value_type;
    using size_type = typename container_type::size_type;

    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;

    void resize(size_type ways, size_type blocks, size_type blockSize);

    /// returns number of ways per block
    size_type ways() const { return m_ways; }
    /// returns number of blocks
    size_type blocks() const { return m_blocks; }
    /// returns number of words per block
    size_type blockSize() const { return m_blockSize; }

    inline uint64_t getTag(uint64_t addr) const
    {
        return addr >> (m_offsetBits + m_indexBits);
    }
    inline uint64_t getBlockIndex(uint64_t addr) const
    {
        return (addr >> m_offsetBits) & ~(getTag(addr) << m_indexBits);
    }

    inline CacheBlock getBlock(uint64_t index)
    {
        size_t baseIdx = index * m_ways;
        return {
            &*m_data.begin() + baseIdx,
            &*m_data.begin() + baseIdx + m_ways
        };
    }

    inline bool empty() const { return m_data.empty(); }

private:
    size_type m_ways = 1;
    size_type m_blocks = 0;
    size_type m_blockSize = 1;

    uint64_t m_offsetBits = 0;
    uint64_t m_indexBits  = 1;

    /// tag cache memory (allocated once at runtime)
    std::vector<CacheEntry> m_data;
};

/// Struct to denote cachable address space
struct AddressSpace
{
    uint64_t lower = 0x0; // inclusive
    uint64_t upper = 0x0; // not inclusive

    /// Whether the address is cachable
    inline bool isCachable(uint64_t addr) const
    {
        return addr >= lower && addr < upper;
    }
};

class Cache
{
public:

    Cache(std::string name = {});
    ~Cache();

    bool fetch(uint64_t address, int& delay);

    /**
     * @brief applyConfig
     * @param config
     * @param configPath Config intern path to cache specific settings
     * @return
     */
    bool applyConfig(etiss::Configuration& config,
                     std::string const& configPath);

    inline std::string const& name() const { return m_name; }

private:

    /// name of cache level (non-functional member)
    std::string m_name{};
    /// address not in cache
    int m_cacheMissDelay = 1;
    /// address in cache (default cache delay)
    int m_cacheHitDelay = 1;
    /// tag cache memory (allocated once at runtime)
    cmm::TagMemory m_tagCache;

    std::function<cmm::CacheEntry*(cmm::CacheBlock&)> m_evictStrategy{};

    // temporaries (for debugging)
    uint t_hits = 0, t_misses = 0, t_evictions = 0;
};

} // namespace cmm

/**
 * @brief Configurable memory model.
 */
class ConfigurableMemoryModel : public ResourceModel
{
    static constexpr size_t MAX_CACHE_COUNT = 5;

public:

    ConfigurableMemoryModel(PerformanceModel* parent_);

    /**
     * @brief Applies memory model configuration
     * @param config_ Config holding memory values
     */
    void applyConfig(etiss::Configuration& config) override;

    /**
     * @brief Delay for accessing the current address`
     * @return Delay
     */
    int getDelay(void) override;

    /// pointer to memory
    /// TODO: more fitting name? Keeping API compatiblity to DCacheModel
    uint64_t* addr_ptr = nullptr;

private:

    /// cachable address space
    cmm::AddressSpace m_addrSpace{};
    /// delay for accessing non cachable memory addresses
    int m_notCachableDelay{};
    /// number of memory levels
    size_t m_cacheCount = 0;
    /// Memory levels
    std::array<cmm::Cache, MAX_CACHE_COUNT> m_caches;

    /**
     * @brief Registers a memory level and applies its configuration
     * @param config
     * @param cacheName
     */
    void registerCache(etiss::Configuration& config, std::string const& cacheName);
};

#endif //CONFIGURABLE_MEMORY_MODEL_H
