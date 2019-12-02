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

		if (start == "start" || start == "Start" || start == "s")
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
		if (in == "stop" || in == "Stop" || in == "quit" || in == "Quit" || in == "s" || in == "q")
		{
			finish();
		//call lap method for all runners
		} else if (in == "all" || in == "All" || in == "a")
		{
			lap(0, clockAtStart);
		//call lap method for a single runner
		} else
		{
			istringstream iss (in);
			iss >> person;
			if (iss.fail()) {
				cout << "Uh-oh" << endl;
				exit(1);
			}
			if (person > people || person < 1)
			{
				cout << "That number is outside the range of people that was set." << endl;
			} else
			{
				lap(person, clockAtStart);
			}
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
			if (splits[i].size() == 1)
			{
				split = total;
				splits[i].push_back(split);
				cout << "Split(" << i << "): ";
				printf("%.2f", split);
				cout << "s" << endl;
			} else
			{
				split = (total - splits[i][0]);
				splits[i].push_back(split);
				splits[i][0] += split;
				cout << "Split(" << i << "): ";
				printf("%.2f", split);
				cout << "s" << endl;
			}
		}
	} else
	{
		//get the lap for a single runner
		split = (total - splits[person-1][0]);
		splits[person-1].push_back(split);
		splits[person-1][0] += split;
		cout << "Split: ";
		printf("%.2f", split);
		cout << "s" << endl;
	}
	//cout << "Split: " << split << endl;
	cout << "Total time: ";
	printf("%.2f", total);
	cout << "s" << endl;
}

void Stopwatch::finish()
{
	int in;

	cout << "Please enter a number for the corresponding option." << endl;
	cout << "1. Print results here." << endl;
	cout << "2. Print results to a txt file." << endl;
	cout << "3. Start a new stopwatch." << endl;
	cout << "4. Exit." << endl;

	cin >> in;

	if (in == 1)
	{
		for (int i = 0; i < people; i++)
		{
			cout << "Athlete #" << i + 1 << ": ";
			for (int j = 1; j < splits[i].size(); j++)
			{
				printf("%.2f", splits[i][j]);
				cout << "s ";
			}
			cout << endl;
		}
	} else if (in == 2)
	{
	} else if (in == 3)
	{
		cout << "Please enter the number of people from 1 to 10 to track with the stopwatch:" << endl;
		cin >> people;
		Stopwatch s(people);
		s.start(people);
	} else if (in == 4)
	{
		exit(0);
	} else
	{
		cout << "Please enter on of the options listed." << endl;
	}
	finish();

}
