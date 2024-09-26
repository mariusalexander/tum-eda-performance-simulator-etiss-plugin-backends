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

class ConfigurableCache
{
public:

    ConfigurableCache(std::string name = {});

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
    };

    /// Helper struct to organize delays of cache actions
    struct Delays
    {
        int notCachable = 1, // address is not cachable
            cacheMiss   = 1, // address not in cache
            cacheHit    = 1, // address in cache (default cache delay)
            cacheReplacement = 1; // delay to replace entry
    };

    /// Helper struct to denote cachable address space
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

    /// name of cache level (non-functional member)
    std::string m_name{};
    /// cachable address space
    AddressSpace m_addrSpace{};
    /// number of ways for n-way set associative caches
    size_t m_nways = 1;
    /// number of lines or blocks (n-ways not accounted for)
    size_t m_nblocks = 1;
    /// number of words per line or block (n-ways not accounted for)
    size_t m_blockSize = 1;

    uint64_t m_offsetBits = 0;
    uint64_t m_indexBits  = 1;
    /// delays for cache actions
    Delays m_delay;
    /// tag cache memory (allocated once at runtime)
    std::vector<CacheEntry> m_tagCache;
};

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

    /// Memory levels
    std::array<ConfigurableCache, MAX_CACHE_COUNT> m_caches;
    /// number of memory levels
    size_t m_cacheCount = 0;

    /**
     * @brief Registers a memory level and applies its configuration
     * @param config
     * @param cacheName
     */
    void registerCache(etiss::Configuration& config, std::string const& cacheName);
};

#endif //CONFIGURABLE_MEMORY_MODEL_H
