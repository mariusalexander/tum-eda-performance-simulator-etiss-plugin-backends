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

#include "models/common/ConfigurableMemoryModel.h"

#include "etiss/Misc.h"

#include <iostream>

#define CONFIG_PATH "plugin.perfEst."

namespace
{

template <typename T, typename U>
inline std::ostream&
operator<<(std::ostream& s, std::pair<T, U> const& t)
{
    return s << '(' << t.first << ", " << t.second << ')';
}

template<typename Iter>
void logIter(std::ostream& s,
             Iter a, Iter b,
             char const* pre,
             char const* suf,
             char const* sep = ", ") noexcept
{
    s << pre;
    if (a != b) // not empty
    {
        Iter b_1 = std::next(a, std::distance(a, b)-1);
        // log until nth - 1 element
        std::for_each(a, b_1, [&s, sep](auto const& val){
            s << val;
            s << sep;
        });
        // log nth element
        s << *b_1;
    }
    s << suf;
}

template<typename K, typename V, typename... R>
std::ostream& operator<<(std::ostream& s, std::map<K, V, R...> const& t)
{
    logIter(s, t.begin(), t.end(), "{\n ", "\n}\n", ",\n ");
    return s;
}

} // namespace

ConfigurableMemoryModel::ConfigurableMemoryModel(PerformanceModel* parent_) :
    ResourceModel("ConfigurableMemoryModel", parent_)
{

}

void
ConfigurableMemoryModel::applyConfig(etiss::Configuration& config)
{
    std::cout << "Applying memory config: " << config.config() << std::endl;

    m_delay = config.get<int>(CONFIG_PATH "memory.delay", -1);
    if (m_delay < 0)
    {
        std::cout << "WARNING: configuration 'memory.delay' not defined! "
                     "Defaulting to '0'" << std::endl;
        m_delay = 0;
    }
    else
    {
        std::cout << "Using delay of '" << m_delay << "'..." << std::endl;
    }

    std::cout << std::endl;
}

int
ConfigurableMemoryModel::getDelay()
{
    return m_delay;
}
