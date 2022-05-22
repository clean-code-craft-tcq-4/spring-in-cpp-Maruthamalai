#include "stats.h"
#include <cmath>
#include <iostream>
#define MAX_THRESHOLD     (10.5f)

//Constructor
Statistics::StatisticsCalc::StatisticsCalc()
{
	m_emailInst = new EmailAlert();
	m_ledAlertInst = new LedAlert();

	std::vector<IAlert*> alerters =
		{ m_emailInst, m_ledAlertInst };

	m_alerter = new StatsAlerter(MAX_THRESHOLD, alerters);

}

//Destructor
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

//Computer min, max, average
Stats Statistics::StatisticsCalc::ComputeStatistics(const std::vector<float> &elements)
{
    Stats computedStats = {NAN, NAN, NAN};
    float total = 0.0;

    // Initialize values
    if (elements.size() > 0)
    {
    	m_alerter->checkAndAlert(elements);
        computedStats.average = 0.0;
        computedStats.min = elements.at(0);
        computedStats.max = elements.at(0);
    }

    // Traverse through array
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

