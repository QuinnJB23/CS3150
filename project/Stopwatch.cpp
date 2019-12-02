#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <bits/stdc++.h>
#include "Stopwatch.h"

using namespace std;

void Stopwatch::start(int people)
{
	bool started = 0;
	string start;
	//wait for the user to enter start
	while (!started)
	{
		cout << "Please type 'start' to start the stopwatch." << endl;
		cin >> start;

		if (start == "start" || start == "Start")
		{
			started = 1;
		}
	}
	double clockAtStart = clock();
	//double currentLap = 0;
	int lapCount = 0;
	bool quit = 0;
	int person;
	string in;
	cout << "Stopwatch started" << endl;
	cout << "Enter athlete number to record their lap or type 'all' to record all athletes laps" << endl;
	//keep stopwatch going until user wants to quit
	while (!quit)
	{
		cin >> in;

		//if users wants to quit then run finish method
		if (in == "stop" || in == "Stop" || in == "quit" || in == "Quit")
		{
			finish();
		//call lap method for all runners
		} else if (in == "all" || in == "All")
		{
			lap(0, clockAtStart);
		//call lap method for a single runner
		} else {
			istringstream iss (in);
			iss >> person;
			if (iss.fail()) {
				cout << "Uh-oh" << endl;
				exit(1);
			}
			lap(person, clockAtStart);
		}

		//currentLap++;
		//cout << "Lap time: ";
		//cout << "Time taken in millisecs: " << clock() - clockAtStart << endl;
		//cout << "Time taken in seconds: " << (clock() - clockAtStart) / 1000 << endl;
		cin.ignore();
	}
}

void Stopwatch::lap(int person, double clockAtStart)
{
	double split;
	double total = (clock() - clockAtStart) / 1000;

	//get the split for all runners
	if (person == 0)
	{
		for(int i = 0; i < people; i++)
		{
			cout << splits[i].size() << " is splits size." << endl;
			if (splits[i].size() == 1)
			{
				split = total;
				splits[i].push_back(split);
				//cout << split << endl;
			} else
			{
				split = (clock() - splits[person-1][0]) / 1000;
				splits[i].push_back(split);
				splits[i][0] += split;
				//cout << split << endl;
			}
		}
	} else
	{
		cout << splits[person-1].size() << " is splits size." << endl;
		//get the lap for a single runner
		split = (clock() - splits[person-1][0] - clockAtStart) / 1000;
		splits[person-1].push_back(split);
		splits[person-1][0] += split;
		//cout << "Split: " << split << endl;
	}
	cout << "Split: " << split << endl;
	cout << "Total time: " << total << endl;
}

void Stopwatch::finish()
{
	bool quit = 0;

	for (int i = 0; i < people; i++)
	{
		for (int j = 1; j < splits[i].size(); j++)
		{
			cout << splits[i][j] << " ";
		}
		cout << endl;
	}
	exit(0);

	/*while (!quit)
	{
		cout << "";
	}*/
}
