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

// TODO: Proof-of-concept model, taken from Robert (more or less)!

#ifndef CV32E40P_D_CACHE_MODEL_H
#define CV32E40P_D_CACHE_MODEL_H

#include <stdbool.h>
#include <cstdint>
#include <string>

#include "PerformanceModel.h"

namespace cv32e40p{

struct DCacheEntry
{
  uint64_t tag = 0;
  bool valid = false;
};

class CustomDCacheModel : public ResourceModel
{
    constexpr static unsigned WAYS=1;
    constexpr static unsigned ROWS=64; 
public:

  // TODO: Check if delays are matching observations!
  CustomDCacheModel(PerformanceModel* parent_) : ResourceModel("ICacheModel", parent_), CACHE_DELAY(1), MEMORY_DELAY(7), NOT_CACHABLE_DELAY(7) {};
  virtual int getDelay(void);

  // Tracing API
  std::string getInfoHeader();
  std::string getInfoStream();
  
  // Trace value
  uint64_t* addr_ptr;
  
private:

  // Cache state
  DCacheEntry tag_cache[WAYS][ROWS];
  
  // Support functions
  bool inCache(uint64_t);
  bool cachable(uint64_t addr_) { return true; };
  void updateCache(uint64_t, uint64_t);
  int lfsr(void);

  // Miss flag. Currently only used for info print
  bool isMiss = false;
  
  // Constants
  const int CACHE_DELAY;
  const int MEMORY_DELAY;
  const int NOT_CACHABLE_DELAY;

};

//CustomDCacheModel::WAYS=2;
//CustomDCacheModel::ROWS=64;

} // namespace cv32e40p
  
#endif // CV32E40P_D_CACHE_MODEL_H
