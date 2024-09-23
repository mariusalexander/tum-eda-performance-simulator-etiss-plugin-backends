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
#include <random>
#include <string>

// path to memory configuartion
#define CONFIG_PATH "plugin.perfEst."

// separator used to parase string list in config file
constexpr char SEPARATOR = ' ';

static std::array<int, ConfigurableMemoryModel::MAX_LEVEL_COUNT> s_histogram;

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
    static_assert(MAX_LEVEL_COUNT > 0, "INVALID MEMORY LEVEL COUNT");
}

ConfigurableMemoryModel::~ConfigurableMemoryModel()
{
    std::cout << "\nConfigurableMemoryModel Historgram: ";
    logIter(std::cout, s_histogram.begin(), s_histogram.begin() + m_levelCount, "[", "]");
    std::cout << std::endl;
}

int
ConfigurableMemoryModel::getDelay()
{
    int delay = 0;
    // iterate over all caches
    for (size_t idx = 0; idx < m_levelCount; ++idx)
    {
        MemoryLevel& level = m_levels[idx];
        delay += level.tacc;

        s_histogram[idx]++;

        // simulate cache hit/miss
        if (level.rhit > (rand() % 10000) * 0.0001) break;
    }
    return delay;
}

void
ConfigurableMemoryModel::applyConfig(etiss::Configuration& config)
{
    std::cout << "Memory config: " << config.config() << std::endl;

    // parse list of memory levels
    std::string levels = config.get<std::string>(CONFIG_PATH "memory.layout", "");

    auto iter = levels.begin();
    auto end = levels.end();

    while (iter != end)
    {
        auto substrEnd = std::find(iter, end, SEPARATOR);
        if (iter == substrEnd) break;

        // create substring until separator
        std::string level{iter, substrEnd};

        iter = substrEnd;
        if (iter != end)
        {
            // iter points to separator -> advance
            iter++;
        }

        appendMemoryLevel(config, level);
    }

    // no memory level added -> use default constructed memory level
    if (m_levelCount == 0)
    {
        std::cout << "WARNING: no memory levels were defined, "
                     "defaulting to no delay!" << std::endl;
        m_levelCount = 1;
    }

    std::cout << std::endl;
}

void
ConfigurableMemoryModel::appendMemoryLevel(etiss::Configuration& config,
                                           std::string const& levelName)
{
    std::cout << "Registering memory level '" << levelName << "'..." << std::endl;

    if (m_levelCount >= m_levels.size())
    {
        throw std::runtime_error("ConfigurableMemoryModel::m_levels is out of memory");
    }

    std::string configPath = CONFIG_PATH "memory." + levelName;

    /// taccess
    auto invalid = std::numeric_limits<unsigned>::max();
    auto tacc = config.get<unsigned>(configPath + ".tacc", invalid);

    if (tacc == invalid)
    {
        std::cout << "WARNING: configuration '" << configPath
                  << ".tacc' not defined! Aborting." << std::endl;
        return;
    }

    /// rhit chance
    // convert to floating point
    auto rhitStr = config.get<std::string>(configPath + ".rhit", "");
    float rhit = atof(rhitStr.c_str());

    if (rhit <= 0.0 || rhit > 1.0)
    {
        rhit = 1.0;
    }

    std::cout << "    tacc: " << tacc << "cc" << std::endl;
    std::cout << "    rhit: " << rhit * 100 << "%" << std::endl;

    // append memory level
    MemoryLevel& level = m_levels[m_levelCount];
    level.rhit = rhit;
    level.tacc = tacc;
    level.name = std::move(levelName);
    m_levelCount++;
}
