#include "EmailAlert.h"

//Number of email alerts sent
unsigned short int EmailAlert::emailSent = 0;

//Constructor
EmailAlert::EmailAlert()
{
	//Do nothig
}

//Destructor
EmailAlert::~EmailAlert()
{

}

//Increase by 1 for every alert request
void EmailAlert::Alerter()
{
	emailSent++;
}

//Get the number of email alerts
unsigned short int EmailAlert::getNumberofEmailAlerts()
{
	return EmailAlert::emailSent;
}
