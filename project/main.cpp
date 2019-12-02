#include <iostream>
#include <ctime>
#include "Stopwatch.h"

using namespace std;

int main()
{
	int in;
	cout << "Please choose one of the following by entering the corresponding number." << endl;
	cout << "1. Multi-person stopwatch." << endl;
	cin >> in;

	if (in == 1)
	{
		cout << "Please enter the number of people from 1 to 10 to track with the stopwatch:" << endl;
		int people;
		cin >> people;
		Stopwatch s(people);
		s.start(people);
	}
}
