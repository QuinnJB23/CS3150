#ifndef STOPWATCH
#define STOPWATCH

#include <iostream>
#include <bits/stdc++.h>
#include "Stopwatch.h"
#include "score.h"

using namespace std;

class Stopwatch
{
	private:
		//initializes a vector for the splits of up to ten people
		vector<vector<double>> splits{ {0},
						{0},
						{0},
						{0},
						{0},
						{0},
						{0},
						{0},
						{0},
						{0} };
		int people;

	public:
		//constructor
		Stopwatch(int people=1):people(people)
		{
			if (people > 10)
			{
				cerr << "Please enter 10 or less people.";
				exit(1);
			}
		}

		//destructor
		~Stopwatch() {}

		void start(int);
		void lap(int, double);
		void finish();

		friend ostream& operator<<(ostream&, const Stopwatch&);

};

#endif
