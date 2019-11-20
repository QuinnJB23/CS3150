#ifndef STOPWATCH
#define STOPWATCH

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stopwatch
{
	private:
		vector<vector<double>> splits;
		int people;

	public:
		Stopwatch(int people=1):people(people)
		{
			cout << "Constructor is working!" << endl;

			for (int i = 0; i < people; i++)
			{
				splits[i][0] = 0;
			}
		}

		~Stopwatch() {cout << "Stopwatch destroyed!";}

		void start(int);
		void lap(int, double);
		void finish();

};

#endif
