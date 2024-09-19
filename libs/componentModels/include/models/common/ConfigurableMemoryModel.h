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

    ConfigurableMemoryModel(PerformanceModel* parent_);

    /**
     * @brief Applies memory model configuration
     * @param config_ Config holding memory values
     */
    void applyConfig(etiss::Configuration& config);

    /**
     * @brief Delay for accessing the current address`
     * @return Delay
     */
    int getDelay(void) override;

    /// pointer to memory
    /// TODO: more fitting name? Keeping API compatiblity to DCacheModel
    uint64_t* addr_ptr = nullptr;

private:

    int m_delay = 0;

};

#endif //CONFIGURABLE_MEMORY_MODEL_H
