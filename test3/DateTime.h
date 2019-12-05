#ifndef DATETIME
#define DATETIME

#include <iostream>
#include "Date.h"

using namespace std;

class DateTime : public Date
{
	public:
		int hours,minutes,seconds;

		DateTime(int day=1, int month=1, int year=1, int hours=1, int minutes=1, int seconds=1):Date(day, month, year), hours(hours), minutes(minutes), seconds(seconds) {}

		virtual ostream& print(ostream&) const;
		virtual istream& read(istream&);
};

#endif
