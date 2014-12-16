#include <Trigger.h>
#include <Arduino.h>
#include <Time.h>

Trigger::Trigger(){

	isEnabled = false;
	state = WAITING;
	activationTime = 0;
	minute = 0;
	hour = 0;
	startTime = 0;

}

void Trigger::setTime(int hour, int minute){

	Trigger::minute = minute;
	Trigger::hour = hour;

}

int getMinute(){

	return Trigger::minute;
}

int getHour(){

	return Trigger::hour;
}

boolean checkTrigger(){

	TimeElements tTime;
	breakTime(now(),tTime);

	tTime.Hour = Trigger::getHour;
	tTime.Minute= Trigger::getMinute;


		if ( (now() >= makeTime(tTime))
			&& (now() < makeTime(tTime)+(Trigger::activationTime*6)) ){

				Trigger::state=Trigger::WATERING;
				return true;
			}
			else
				{
				Trigger::state=Trigger::WAITING;
				return false;
				}




	}

void setActivationTime(int minutes){

Trigger::activationTime = minutes;

}
