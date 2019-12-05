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
		Date(int month=1, int day=1, int year=1)
		{
			if (month > 12 || month < 1)
			{
				month = 1;
			}
			
			if (day > 31 || day < 1)
			{
				day = 1;
			}

			if (year < 1)
			{
				year = 1;
			}

			this->month = month;
			this->day = day;
			this->year = year;
		}

		Date operator++();
		Date operator++(int);
		Date operator+(int);
		Date operator-(int);
		Date operator=(Date&);
		bool operator>(const Date&);
		bool operator<(const Date&);
		bool operator==(const Date&);

		virtual ostream& print(ostream&) const;
		virtual istream& read(istream&);
		friend ostream& operator<<(ostream&, const Date&);
		friend istream& operator>>(istream&, Date&);

		Date(const Date&);

		~Date() {}


};

#endif
