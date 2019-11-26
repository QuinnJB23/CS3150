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
	double currentLap = 0;
	int lapCount = 0;
	bool quit = 0;
	int person;
	string in;
	cout << "Stopwatch started" << endl;
	cout << "Enter athlete number to record their lap or type 'all' to record all athletes laps" << endl;
	while (!quit)
	{
		cin >> in;
		if (in == "stop" || in == "Stop")
		{
			finish();
		} else if (in == "all" || in == "All")
		{
			lap(0, clockAtStart);
		} else {
			istringstream iss (in);
			iss >> person;
			if (iss.fail()) {
				cout << "Uh-oh" << endl;
				exit(1);
			}
			lap(person, clockAtStart);
		}

		currentLap++;
		cout << "Lap time: ";
		cout << "Time taken in millisecs: " << clock() - clockAtStart << endl;
		cout << "Time taken in seconds: " << (clock() - clockAtStart) / 1000;
		cin.ignore();
	}
}

void Stopwatch::lap(int person, double clockAtStart)
{
	double split;

	if (person == 0)
	{
		for(int i = 0; i < people; i++)
		{
			if (splits[i].size() == 1)
			{
				split = clock() - clockAtStart;
				splits[i].push_back(split);
				cout << split << endl;
			} else
			{
				split = clock() - splits[person-1][0];
				splits[i].push_back(split);
				splits[i][0] += split;
				cout << split << endl;
			}
		}
	} else if (splits[person-1].size() == 1)
	{
		split = clock() - clockAtStart;
		splits[person-1].push_back(split);
		cout << split << endl;
	} else
	{
		split = clock() - splits[person-1][0];
		splits[person-1].push_back(split);
		splits[person-1][0] += split;
		cout << split << endl;
	}
}

void Stopwatch::finish()
{
	bool quit = 0;

	while (!quit)
	{
		cout << "";
	}
}
