/*
 * Copyright 2023 Chair of EDA, Technical University of Munich
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

#ifndef SWEVAL_BACKENDS_PERFORMANCE_ESTIMATOR_H
#define SWEVAL_BACKENDS_PERFORMANCE_ESTIMATOR_H

#include "Channel.h"
#include "Backend.h"
#include "PerformanceModel.h"

#include <cstdint>

using std::uint64_t;

class PerformanceEstimator: public Backend
{
 public:
  PerformanceEstimator(PerformanceModel* perfModel_) : perfModel_ptr{perfModel_} {};
  ~PerformanceEstimator();

  void connectChannel(Channel* channel_);
  void initialize(void);
  void execute(void);
  void finalize(void);

  /**
   * @brief Forwards configuration to performance model
   * @param config
   */
  void applyConfig(etiss::Configuration& config_);
  
 private:
  PerformanceModel* perfModel_ptr;

  // Pointer to channel content
  uint64_t* ch_typeId_ptr;
  uint64_t* ch_instrCnt_ptr;
  
  uint64_t globalInstrCnt = 0;
};

#endif //SWEVAL_BACKENDS_PERFORMANCE_ESTIMATOR_H
