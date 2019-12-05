#ifndef DATETIME
#define DATETIME

#include <iostream>
#include "Date.h"

using namespace std;

class DateTime : public Date
{
	public:
		int hours,minutes,seconds;

		DateTime(int day, int month, int year, int hours, int minutes, int seconds):Date(day, month, year), hours(hours), minutes(minutes), seconds(seconds) {}
};

#endif
