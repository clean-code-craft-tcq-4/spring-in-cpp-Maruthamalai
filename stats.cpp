#include "stats.h"
#include <cmath>
#include <iostream>
#define MAX_THRESHOLD     (10.5)

Statistics::StatisticsCalc::StatisticsCalc()
{
	emailInst = new EmailAlert();
	ledAlertInst = new LedAlert();
}
Statistics::StatisticsCalc::~StatisticsCalc()
{
/*	if(emailInst)
	{
		delete emailInst;
	}
	if(ledAlertInst)
	{
		delete ledAlertInst;
	}*/
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

/*

int main()
{
    Statistics::StatisticsCalc* computeObj = new Statistics::StatisticsCalc();
    
    auto computedStats =  computeObj->ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    std::cout << computedStats.average << std::endl;
    std::cout << computedStats.max << std::endl;
    std::cout << computedStats.min << std::endl;
    if ((computedStats.average - 4.525) < epsilon)
    {
        std::cout << "Avg ok" << std::endl;
    }
    if ((computedStats.max - 8.9) < epsilon)
    {
       std:: cout << "Max ok" << std::endl;
    }
    if ((computedStats.min - 1.5) < epsilon)
    {
        std::cout << "Min ok" << std::endl;
    }
    else
    {
    }
    return 0;
}
*/
