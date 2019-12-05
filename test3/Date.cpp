#include <iostream>
#include "Date.h"

using namespace std;

Date Date::operator=(Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;

	return *this;
}

Date Date::operator++()
{
	if (day == 31)
	{
		if (month == 12)
		{
			month = 1;
			year++;
		} else
		{
			month++;
		}
		day = 1;
	} else
	{
		day++;
	}
	
	return *this;
}

Date Date::operator++(int)
{
	Date temp = *this;

	if (day == 31)
	{
		if (month == 12)
		{
			month = 1;
			year++;
		} else
		{
			month++;
		}
		day = 1;
	} else
	{
		day++;
	}

	return temp;
}

ostream& operator<<(ostream& ost, const Date& d)
{
	return ost << d.month << '-' << d.day << '-' << d.year;
}

istream& operator>>(istream& ist, Date& d)
{
	cout << "month = ";
	ist >> d.month;

	cout << "day = ";
	ist >> d.day;

	cout << "year = ";
	ist >> d.year;

	return ist;
}

Date Date::operator+(int a)
{
	bool done;
	day += a;
	while (!done)
	{
		if (day > 31)
		{
			month++;
			day -= 31;
			if (month > 12)
			{
				month = 1;
				year++;
			} else
			{
				month++;
			}
		} else
		{
			done = 1;
		}
	}

	return *this;
}

Date Date::operator-(int a)
{
	bool done = 0;
	day -= a;
	while (!done)
	{
		if (day < 1)
		{
			month--;
			day += 31;
			if (month < 1)
			{
				month = 12;
				year--;
			}
		} else
		{
			done = 1;
		}
	}

	return *this;
}

bool Date::operator>(const Date& d)
{
	if (year == d.year)
	{
		if (month == d.month)
		{
			if (day <= d.day)
			{
				return false;
			}
		}
		if (month < d.month)
		{
			return false;
		}
	}
	if (year < d.year)
	{
		return false;
	}

	return true;
}

bool Date::operator<(const Date& d)
{
	if (year == d.year)
	{
		if (month == d.month)
		{
			if (day >= d.day)
			{
				return false;
			}
		}
		if (month > d.month)
		{
			return false;
		}
	}
	if (year > d.year)
	{
		return false;
	}

	return true;
}

bool Date::operator==(const Date& d)
{
	if (day != d.day || month != d.month || year != d.year)
	{
		return false;
	}
	return true;
}

Date::Date(const Date& old_dte)
{
	day = old_dte.day;
	month = old_dte.month;
	year = old_dte.year;
}
