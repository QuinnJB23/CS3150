#ifndef DATE
#define DATE

#include <iostream>

using namespace std;

class Date
{
	private:
		//int day,month,year;

	public:
		int day,month,year;
		Date(int month=1, int day=1, int year=1):month(month), day(day), year(year){}

		Date operator++();
		Date operator++(int);
		Date operator+(int);
		Date operator-(int);
		Date operator=(Date&);
		bool operator>(const Date&);
		bool operator<(const Date&);
		bool operator==(const Date&);

		friend ostream& operator<<(ostream&, const Date&);
		friend istream& operator>>(istream&, Date&);

		Date(const Date&);

		~Date() {}


};

#endif
