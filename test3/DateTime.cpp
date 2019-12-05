#include <iostream>
#include "DateTime.h"
#include "Date.h"

using namespace std;


ostream& DateTime::print(ostream& ost) const
{
	return Date::print(ost) << ' ' << hours << ':' << minutes << ':' << seconds;
}

istream& DateTime::read(istream& ist)
{
	Date::read(ist);

	cout << "hours = ";
	ist >> hours;

	cout << "minutes = ";
	ist >> minutes;

	cout << "seconds = ";
	ist >> seconds;

	return ist;
}
