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

#ifndef CV32E40P_CUSTOM_I_CACHE_MODEL_H
#define CV32E40P_CUSTOM_I_CACHE_MODEL_H

#include <stdbool.h>
#include <cstdint>
#include <string>

#include "PerformanceModel.h"

namespace cv32e40p{

struct ICacheEntry
{
  uint64_t tag = 0;
  bool valid = false;
};

class CustomICacheModel : public ResourceModel
{
    constexpr static unsigned WAYS=1;
    constexpr static unsigned ROWS=32; 
public:

  CustomICacheModel(PerformanceModel* parent_) : ResourceModel("CustomICacheModel", parent_), CACHE_DELAY(1), MEMORY_DELAY(5) {};
  virtual int getDelay(void);
  
  void setIc_in(uint64_t c_) { t_ic = isMiss ? c_ : 0; };
  uint64_t getIc_out(void) { return t_ic; };

  // Tracing API
  std::string getInfoHeader();
  std::string getInfoStream();
  
  // Trace value
  uint64_t* pc_ptr;
  
private:
  
  // Cache state
  // TODO: Associativity hard-coded to 4
  ICacheEntry tag_cache[WAYS][ROWS];
  //bool valid_cache[4][256]= {false};
  bool isMiss = false;

  // Time when ICache relaeses block on miss
  uint64_t t_ic = 0;
  
  // Constants
  const int CACHE_DELAY;
  const int MEMORY_DELAY;

  // Support functions
  bool inCache(uint64_t);
  bool cachable(uint64_t pc_) { return true; };
  void updateCache(uint64_t, uint64_t);
  int lfsr(void);
};

//CustomICacheModel::WAYS=2;
//CustomICacheModel::ROWS=64;

} // namespace cv32e40p  
  
#endif // CV32E40P_CUSTOM_I_CACHE_MODEL_H
