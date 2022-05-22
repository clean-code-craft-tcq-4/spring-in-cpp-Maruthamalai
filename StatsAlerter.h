#ifndef STATS_ALERTER_H
#define STATS_ALERTER_H
#include "EmailAlert.h"
#include "LedAlert.h"
#include <vector>

class IAlert;

class StatsAlerter
{
private:
	float maxThreshold;
	std::vector<IAlert*> Alerter;

public:
	StatsAlerter(float maxThreshold, std::vector<IAlert*> alerter);
	~StatsAlerter();
	void checkAndAlert(const std::vector<float> &elements);
};

#endif
