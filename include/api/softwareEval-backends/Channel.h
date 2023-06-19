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

#ifndef SWEVAL_BACKENDS_CHANNEL_H
#define SWEVAL_BACKENDS_CHANNEL_H

#include <string>
#include <stdbool.h>

class Channel
{
public:

    Channel() { instrCnt = 0; };
    ~Channel() = default;

    int instrCnt;
    int typeId [100];

    virtual void *getTraceValueHook(std::string)=0;
};

#endif //SWEVAL_BACKENDS_CHANNEL_H
