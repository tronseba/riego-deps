#ifndef _Trigger_H
#define _Trigger_H

#include <Time.h>

class Trigger {

	public:
		static const int WATERING = 1;
		static const int WAITING = 2;
		static const int LUNES = 0;
		static const int MARTES = 1;
		static const int MIERCOLES = 2;
		static const int JUEVES = 3;
		static const int VIERNES = 4;
		static const int SABADO = 5;
		static const int DOMINGO  = 6;

		boolean weekDays[7] = { false, false, false, false,false, false, false };

		Trigger();
		void setTime(int hour, int minute);
		int getMinute();
		int getHour();
		boolean checkTrigger();
		void setActivationTime(int minutes);


	private:

		boolean isEnabled;
		int activationTime;
		int state;
		int minute;
		int hour;
		int startTime;

};
#endif
