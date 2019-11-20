#include <iostream>
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
	string in;
	cout << "Stopwatch started" << endl;
	while (!quit)
	{
		cin >> in;
		if (in == "stop" || in == "Stop")
		{
			finish();
		} else if (in == "lap" || in == "Lap")
		{
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
	if (splits[person-1].size() == 1)
	{
		split = clock() - clockAtStart;
		splits[person-1].push_back(split);
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
