#include <iostream>
#include "Date.h"
#include "Datetime.h"

using namespace std;

int main()
{
	Date d1;
	Date d2(5, 5, 5);

	//=
	cout << "d1 before: " << d1 << endl;
	d1 = d2;
	cout << "d1 after: " << d1 << endl;

	//++
	cout << "d1 pre-increment: " << ++d1 << " d1 post-increment: " << d1++ << " : " << d1 << endl;
	Date d3(12, 31, 2019);
	cout << d3 << " goes to: " << ++d3 << endl;

	//>>
	cout << "d1:" << endl;
	cin >> d1;
	cout << "d1 now is: " << d1 << endl;

	//+
	cout << "d2 before: " << d2 << " d2 adding 45: " << d2 + 45 << endl;

	//-
	cout << "now d2 subtracing 500: " << d2 - 500 << endl;

	//> < ==
	cout << "d1:" << endl;
	cin >> d1;
	cout << "d2:" << endl;
	cin >> d2;
	cout << "d1: " << d1 << " d2: " << d2 << endl;
	if (d1 > d2)
	{
		cout << "d1 is greater than d2" << endl;
	} else if (d1 < d2)
	{
		cout << "d1 is less than d2" << endl;
	} else if (d1 == d2)
	{
		cout << "d1 is equal to d2" << endl;
	} else
	{
		cout << "Somthing is wrong." << endl;
	}
}
