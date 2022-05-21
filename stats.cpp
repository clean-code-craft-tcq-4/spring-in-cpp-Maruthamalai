#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float> &elements)
{
    Stats computedStats = {0.0, 0.0, 0.0};
    float total = 0.0;
    for (auto& it:elements)
    {
        total+= it;

        if(it>computedStats.max)
        {
            computedStats.max = it;
        }

        if(it<computedStats.min)
        {
            computedStats.min = it;
        }
    }
computedStats.average = total / elements.size();

return computedStats;

}
