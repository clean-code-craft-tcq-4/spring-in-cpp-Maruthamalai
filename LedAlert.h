#ifndef LED_ALERT_H
#define LED_ALERT_H

#include "IAlert.h"

class LedAlert: public IAlert
{
private:
	static unsigned short ledGlows;
public:
	LedAlert();
	~LedAlert();
	void Alerter();
	unsigned short getNumberofEmailAlerts();
};

#endif
