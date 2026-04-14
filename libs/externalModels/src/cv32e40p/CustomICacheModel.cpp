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

#include <cstdint>
#include <string>
#include <sstream>
#include <cmath>
#include <cassert>

#include "models/cv32e40p/CustomICacheModel.h"

namespace cv32e40p{

int CustomICacheModel::getDelay(void)
{
    uint64_t pc = pc_ptr[getInstrIndex()];

    isMiss = !inCache(pc);

    if(!cachable(pc) | isMiss)
    {
        return MEMORY_DELAY;
    }
    return CACHE_DELAY;
}

bool CustomICacheModel::inCache(uint64_t pc_)
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

    uint64_t tag = pc_ >> (offsetBits + indexBits);
    uint64_t index = (pc_ >> offsetBits) & ~(tag << indexBits);

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

void CustomICacheModel::updateCache(uint64_t tag_, uint64_t index_)
{
    int way = -1;

    for(int i=0; i<WAYS; i++)
    {
      if(!tag_cache[i][index_].valid)
      {
	way = i;
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

int CustomICacheModel::lfsr(void)
{
    static uint8_t shift_state = 0;
    uint8_t shift_in = ~(((shift_state & 0x80) >> 7) ^ ((shift_state & 0x08) >> 3) ^ ((shift_state & 0x04) >> 2) ^ ((shift_state & 0x02) >> 1));
    shift_state = (shift_state << 1) | (shift_in & 0x01);
    return (shift_state % WAYS);
}

std::string CustomICacheModel::getInfoHeader()
{
  std::stringstream ret_strs;
  ret_strs << "L1I_delay";
  return ret_strs.str();
}

std::string CustomICacheModel::getInfoStream()
{
  std::stringstream ret_strs;
  ret_strs << (isMiss ? MEMORY_DELAY : CACHE_DELAY);
  return ret_strs.str();
}

} // namespace cv32e40p
