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

ostream& Date::print(ostream& ost) const
{
	return ost << month << '-' << day << '-' << year;
}

ostream& operator<<(ostream& ost, const Date& d)
{
	return d.print(ost);
}

istream& Date::read(istream& ist)
{
	cout << "month = ";
	ist >> month;

	cout << "day = ";
	ist >> day;

	cout << "year = ";
	ist >> year;

	return ist;
}

istream& operator>>(istream& ist, Date& d)
{
	return d.read(ist);
}

Date Date::operator+(int a)
{
	bool done = 0;
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
