#include "EmailAlert.h"

unsigned short int EmailAlert::emailSent = 0;
EmailAlert::EmailAlert()
{
	//Do nothig
}
EmailAlert::~EmailAlert()
{

}

void EmailAlert::Alerter()
{
	emailSent++;
}
unsigned short int EmailAlert::getNumberofEmailAlerts()
{
	return EmailAlert::emailSent;
}
