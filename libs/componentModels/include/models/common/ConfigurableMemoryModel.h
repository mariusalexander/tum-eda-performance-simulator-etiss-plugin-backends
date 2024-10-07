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
#include <algorithm>

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

/// Cache block/line which holds multiple cache entries
struct CacheBlock
{
    /// start of range
    CacheEntry* begin_{};
    /// end of range
    CacheEntry* end_{};

    CacheEntry* begin() { return begin_; }
    CacheEntry* end() { return end_; }

    /**
     * @brief Attempts to find a cache entry with the given tag
     * @return Cache entry with the given tag (may be null)
     */
    inline cmm::CacheEntry* findEntry(uint64_t tag)
    {
        auto iter = std::find_if(begin(), end(), [tag](const CacheEntry& e){
            return e.tag == tag;
        });

        if (iter == end()) return nullptr;
        return &*iter;
    }

    /**
     * @brief Attempts to find a cache entry that is invalid
     * @return Cache entry that is invalid (may be null)
     */
    inline cmm::CacheEntry* findInvalidEntry()
    {
        auto iter = std::find_if(begin(), end(), [](const CacheEntry& e){
            return !e.isValid();
        });

        if (iter == end()) return nullptr;
        return &*iter;
    }
};

/// Implements a tag memory of a cache and provides simple access to
/// cache blocks and entries
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

/// Struct to denote a cachable address space
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

/// Struct to hold cache delays
struct CacheDelays
{
    /// address in cache (default cache delay)
    int hit = 1;
    /// address not in cache
    int miss = 1;
};

class Cache
{
public:

    /// strategy to chose an entry to evict
    using EvictionStrategy = std::function<cmm::CacheEntry*(cmm::CacheBlock&)>;
    /// strategy to check if entry is valid
    using IsValidStrategy = std::function<bool(cmm::CacheEntry&)>;

    Cache(std::string name,
          TagMemory memory,
          CacheDelays delays,
          IsValidStrategy isValidStrategy,
          EvictionStrategy evictionStrategy);
    ~Cache();

    bool fetch(uint64_t address, int& delay);

    inline std::string const& name() const { return m_name; }

private:

    /// name of cache level (non-functional member)
    std::string m_name{};
    /// delays for cache actions
    CacheDelays m_delays;
    /// tag cache memory
    TagMemory m_tagMemory;
    /// strategy to check if entry is valid
    IsValidStrategy m_isValidStrategy{};
    /// strategy to evict entry
    EvictionStrategy m_evictStrategy{};

    void update(CacheBlock block,
                CacheEntry& entry);

    void writeback(CacheEntry& entry);

    void replace(CacheBlock block,
                 uint64_t tag);

    // temporaries (for debugging/statistics)
    unsigned t_hits = 0, t_misses = 0, t_evictions = 0;
};

} // namespace cmm

/**
 * @brief Configurable memory model.
 */
class ConfigurableMemoryModel : public ResourceModel
{
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
    /// Memory levels
    std::vector<cmm::Cache> m_caches;
    /// delay for accessing non cachable memory addresses
    int m_notCachableDelay = 0;

    /**
     * @brief Registers a memory level and applies its configuration
     * @param config
     * @param cacheName
     */
    bool registerCache(etiss::Configuration& config, std::string const& cacheName);
};

#endif //CONFIGURABLE_MEMORY_MODEL_H
