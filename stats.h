#ifndef STATS_H
#define STATS_H

#include <vector>
#include "EmailAlert.h"
#include "LedAlert.h"

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
	Stats statsElements;
	EmailAlert *emailInst;
	LedAlert *ledAlertInst;

public:
	StatisticsCalc();
	~StatisticsCalc();
	Stats ComputeStatistics(const std::vector<float>&);
};

}

#endif
