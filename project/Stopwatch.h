#ifndef STOPWATCH
#define STOPWATCH

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stopwatch
{
	private:
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
		Stopwatch(int people=1):people(people)
		{
			cout << "Constructor is working!" << endl;
			if (people > 10)
			{
				cerr << "Please enter 10 or less people.";
				exit(1);
			}
		}

		~Stopwatch() {cout << "Stopwatch destroyed!";}

		void start(int);
		void lap(int, double);
		void finish();

};

#endif
