#include "StatsAlerter.h"

StatsAlerter::StatsAlerter(float maxThres, std::vector<IAlert*> alerter) :
		maxThreshold(maxThres), Alerter(alerter)
{

}

StatsAlerter::~StatsAlerter()
{

}

void StatsAlerter::checkAndAlert(const std::vector<float> &elements)
{

}
