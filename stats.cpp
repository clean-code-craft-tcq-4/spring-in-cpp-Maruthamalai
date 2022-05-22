#include "stats.h"
#include <cmath>
#include <iostream>

Statistics::StatisticsCalc::StatisticsCalc()
{
}
Statistics::StatisticsCalc::~StatisticsCalc()
{
}

Stats Statistics::StatisticsCalc::ComputeStatistics(const std::vector<float> &elements)
{
    Stats computedStats = {NAN, NAN, NAN};
    float total = 0.0;

    // Initialise valules
    if (elements.size() > 0)
    {
        computedStats.average = 0.0;
        computedStats.min = elements.at(0);
        computedStats.max = elements.at(0);
    }

    // Travese through array
    for (auto &it : elements)
    {
        total += it;

        if (it > computedStats.max)
        {
            computedStats.max = it;
        }

        if (it < computedStats.min)
        {
            computedStats.min = it;
        }
    }
    computedStats.average = total / elements.size();

    return computedStats;
}

