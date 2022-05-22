#ifndef EMAIL_ALERT_H
#define EMAIL_ALERT_H
#include "IAlert.h"

class EmailAlert: public IAlert
{
private:
	static unsigned short int emailSent;
public:
	EmailAlert();
	~EmailAlert();
	void Alerter();
	unsigned short int getNumberofEmailAlerts();
};

#endif
