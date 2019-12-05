#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>

#include "score.h"

using namespace std;

void scoreMeet()
{
	unsigned char b;
	int tab = 0;
	int tempI;
	int in;
	string tempS = "";
	bool check = 0;
	vector<int> score;
	vector<string> teams;

	ifstream inf("xcmeet.txt");

	if (!inf)
	{
		cerr << "unable to open file for writing!" << endl;
		exit(1);
	}

	inf >> noskipws;

	while(inf >> b)
	{ 
		cout << "b: " << b << endl;
		if (tab == 0)
		{
			cout << "b: " << b << endl;
			tempI = b;
			cout << "tempI: " << tempI << endl;
		}
		if (b == '\t')
		{
			tab++;
		}
		if (tab == 2)
		{
			while (b != '\n' && inf >> b)
			{
				cout << "1" << endl;
				tempS += b;
				inf >> b;
			}
			for (int i = 0; i < teams.size(); i++)
			{
				if (teams[i] == tempS)
				{
					cout << "teams spot: " << i << " " << tempS << endl;
					score[i] += tempI;
					check = 1;
				}
			}
			if (!check)
			{
				cout << " " << tempI << endl;
				cout << " " << tempS << endl;
				score.push_back(tempI);
				teams.push_back(tempS);
			}
			tab = 0;
			tempS = "";
			tempI = 0;
		}

	}
	inf.close();

	cout << "1: Print the results here." << endl;
	cout << "2: Print the results to a text file." << endl;
	cin >> in;

	if (in == 1)
	{
		printScore(score, teams);
	} else if (in == 2)
	{
		printScore(score, teams);
	}
}


void printScore(vector<int> score, vector<string> teams)
{
	cout << "Team\t\tPoints\n";
	for (int i = 0; i < teams.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (score[i] < score[j])
			{
				swap(score[i], score[j]);
				swap(teams[i], teams[j]);
			}
		}
	}
	for (int i = 0; i < teams.size(); i++)
	{
		cout << i + 1 << ". " << teams[i] << '\t' << score[i] << '\n';
	}
}
