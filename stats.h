#ifndef STATS_H
#define STATS_H

#include <vector>
#include "EmailAlert.h"
#include "LedAlert.h"
#include "StatsAlerter.h"
typedef struct
{

	double average;
	double max;
	double min;
} Stats;

namespace Statistics
{
class StatisticsCalc
{
private:
	/* data */
	Stats m_statsElements;
	EmailAlert *m_emailInst;
	LedAlert *m_ledAlertInst;
	StatsAlerter *m_alerter;

public:
	StatisticsCalc();
	~StatisticsCalc();
	Stats ComputeStatistics(const std::vector<float>&);
};

}

#endif
