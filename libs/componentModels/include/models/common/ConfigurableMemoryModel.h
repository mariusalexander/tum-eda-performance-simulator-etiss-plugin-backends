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

/**
 * @brief Memory model with configurable delay.
 */
class ConfigurableMemoryModel : public ResourceModel
{
public:
    static constexpr size_t MAX_LEVEL_COUNT = 5;

    /// Memory level in a hierarchical memory system (e.g. L1 cache)
    struct MemoryLevel
    {
        /// hit rate
        float rhit = 1.0;
        /// access time
        int tacc = 1;
        /// level name, used for debugging
        std::string name;
    };

    ConfigurableMemoryModel(PerformanceModel* parent_);
    ~ConfigurableMemoryModel() override;

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
    std::array<MemoryLevel, MAX_LEVEL_COUNT> m_levels;
    /// number of memory levels
    size_t m_levelCount = 0;

    /**
     * @brief Registers a memory level and applies its configuration
     * @param config
     * @param level
     */
    void appendMemoryLevel(etiss::Configuration& config, std::string const& level);
};

#endif //CONFIGURABLE_MEMORY_MODEL_H
