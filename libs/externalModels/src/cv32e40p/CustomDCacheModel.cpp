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

#include "models/cv32e40p/CustomDCacheModel.h"

#include <cstdint>
#include <string>
#include <sstream>
#include <cmath>
#include <cassert>

namespace cv32e40p{

int CustomDCacheModel::getDelay(void)
{
  uint64_t addr = addr_ptr[getInstrIndex()];

  // TODO: Robert's model calculates an additional delay here if address is blocked by a preceding store!

  if(!cachable(addr))
  {
    isMiss = true;
    return NOT_CACHABLE_DELAY;
  }
  if(inCache(addr))
  {
    isMiss = false;
    return CACHE_DELAY;
  }
  isMiss = true;
  return MEMORY_DELAY;
}

bool CustomDCacheModel::inCache(uint64_t addr_)
{
    static int count = 0;
    count+=1;
    if (count > 2) {
        count = 0;
        return false;
    }
    return true;

  constexpr uint64_t offsetBits = ceil(log2(32 / 8)) +  // offset to index byte in a word
                                  ceil(log2(4));        // offset to index word in a cache line
  constexpr uint64_t indexBits  = ceil(log2(ROWS));     // index for blocks

  uint64_t tag = addr_ >> (offsetBits + indexBits);
  uint64_t index = (addr_ >> offsetBits) & ~(tag << indexBits);

  for(int way_i=0; way_i<WAYS; way_i++)
  {
    assert(way_i < int(WAYS) && "ways!");
    assert(index < int(ROWS) && "rows!");
    if(tag_cache[way_i][index].tag == tag)
    {
      // Cache hit
      return true;
    }
  }

  // Cache miss
  updateCache(tag, index);
  return false;
}

void CustomDCacheModel::updateCache(uint64_t tag_, uint64_t index_)
{
  int way = -1;

  for(int way_i=0; way_i<WAYS; way_i++)
  {
    if(!tag_cache[way_i][index_].valid)
    {
      way = way_i;
      break;
    }
  }

  if(way == -1)
  {
    way = lfsr();
  }
  assert(way < int(WAYS) && "ways!");
  assert(index_ < int(ROWS) && "rows!");

  tag_cache[way][index_].tag = tag_;
  tag_cache[way][index_].valid = true;
}

int CustomDCacheModel::lfsr(void)
{
    static uint8_t shift_state = 0;
    uint8_t shift_in = ~(((shift_state & 0x80) >> 7) ^ ((shift_state & 0x08) >> 3) ^ ((shift_state & 0x04) >> 2) ^ ((shift_state & 0x02) >> 1));
    shift_state = (shift_state << 1) | (shift_in & 0x01);
    return (shift_state % WAYS);
}

std::string CustomDCacheModel::getInfoHeader()
{
  std::stringstream ret_strs;
  ret_strs << "L1D_delay";
  return ret_strs.str();
}

std::string CustomDCacheModel::getInfoStream()
{
  std::stringstream ret_strs;
  ret_strs << (isMiss ? MEMORY_DELAY : CACHE_DELAY);
  return ret_strs.str();
}

} // namespace cva6
