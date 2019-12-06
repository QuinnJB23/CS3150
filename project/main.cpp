#include <iostream>
#include <ctime>
#include "Stopwatch.h"

using namespace std;

int main()
{
	//input for choices
	int in;
	bool ok = 0;
	cout << "Please choose one of the following by entering the corresponding number." << endl;
	cout << "1. Multi-person stopwatch." << endl;
	cout << "2. Cross country meet scorer" << endl;
	cin >> in;

	if (in == 1)
	{
		//start stop watch with the entered number of people
		int people;
		while (!ok)
		{
			cout << "Please enter the number of people from 1 to 10 to track with the stopwatch:" << endl;
			cin >> people;
			if (people < 1 || people > 10)
			{
				cout << "You have entered invalid input, please try again." << endl;
			} else
			{
				ok = 1;
			}
		}
		Stopwatch s(people);
		s.start(people);
	} else if (in == 2)
	{
		scoreMeet();
	}
}
