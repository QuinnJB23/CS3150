#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
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

			//convert input to int
			istringstream iss (in);
			try{
			iss >> person;
			}

			catch (exception& e) {
				cout << "exception caught";
			}

			
			//if option was invalid
			if (person > people || person < 1)
			{
				cout << "That is not a number or is outside the range of people that was set." << endl;
			} else
			{
				lap(person, clockAtStart);
			}
		}

		cin.ignore();
	}
}

void Stopwatch::lap(int person, double clockAtStart)
{
	double split;
	double total = (clock() - clockAtStart) / 1000;

	//get the new split for all runners
	if (person == 0)
	{
		//cycle through all people
		for(int i = 0; i < people; i++)
		{
			//if a split hasn't been recorded then just add total time to the back
			if (splits[i].size() == 1)
			{
				split = total;
				splits[i].push_back(split);
				cout << "Split(" << i << "): ";
				printf("%.2f", split);
				cout << "s" << endl;
			} else
			{
				//subtract total time from the first spot in the vector which keeps track of the total time after each split is taken
				split = (total - splits[i][0]);
				splits[i].push_back(split);
				splits[i][0] += split;
				cout << "Split(" << i << "): ";

				//only get 2 decimal places
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
	double temp;

	//print options
	cout << "Please enter a number for the corresponding option." << endl;
	cout << "1. Print results here." << endl;
	cout << "2. Print results to a txt file." << endl;
	cout << "3. Start a new stopwatch." << endl;
	cout << "4. Exit." << endl;

	cin >> in;

	if (in == 1)
	{
		//prints results using the overloaded operator <<
		cout << *this;
	} else if (in == 2)
	{

		//get file ready for writing
		ofstream outf("splits.txt");
		
		if (!outf)
		{
			cerr << "unable to open file for writing!" << endl;
			exit(1);
		}

		//use overloaded operator << to put all splits to a text file
		outf << *this;

	} else if (in == 3)
	{
		//start new stop watch
		cout << "Please enter the number of people from 1 to 10 to track with the stopwatch:" << endl;
		cin >> people;
		Stopwatch s(people);
		s.start(people);
	} else if (in == 4)
	{
		//exit
		exit(0);
	} else
	{
		//if user entered an invalid option
		cout << "Please enter on of the options listed." << endl;
	}

	//recall finish() if exit wasn't chosen
	finish();

}

//prints out all splits sorted by person using the << operator
ostream& operator<<(ostream& ost, const Stopwatch& s)
{
	//cycle through each person's vector
	for (int i = 0; i < s.people; i++)
	{
		//print which athlete for the row
		ost << "Athlete #" << i + 1 << ": ";
		for (int j = 1; j < s.splits[i].size(); j++)
		{
			//print each split to 2 decimal places
			ost << fixed << setprecision(2) << s.splits[i][j];
			ost << "s ";
		}
		ost << "Total time: " << s.splits[i][0] << '\n';
	}
	
	return ost;
}
