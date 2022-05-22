#include "LedAlert.h"

unsigned short int LedAlert::ledGlows = 0;

LedAlert::LedAlert()
{
	//Do nothig
}

LedAlert::~LedAlert()
{

}
void LedAlert::Alerter()
{
	ledGlows++;
}
unsigned short int LedAlert::getNumberofLedAlerts()
{
	return LedAlert::ledGlows;
}
