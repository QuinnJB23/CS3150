#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>

#include "score.h"

using namespace std;

void scoreMeet()
{
	//initialize variables
	int bi;
	unsigned char b;
	int tab = 0;
	int tempI;
	int in;
	string tempS = "";
	bool check = 0;
	vector<int> score;
	vector<string> teams;
	vector<int> rCount;

	//set up input stream
	ifstream inf("xcmeet.txt");

	if (!inf)
	{
		cerr << "unable to open file for reading!" << endl;
		exit(1);
	}

	//don't skip whitespace
	inf >> noskipws;

	//get the first value in the file which should be an int
	inf >> bi;
	tempI = bi;

	//keep getting values from the file until it finishes
	while(inf >> b)
	{ 

		//count all tabs
		if (b == '\t')
		{
			tab++;
		}

		if (tab == 2)
		{
			while (inf >> b && b != '\n')
			{
				//take in the team name as a string
				tempS += b;
			}
			for (int i = 0; i < teams.size(); i++)
			{
				//if a team has already been entered into the teams vector then add to their score
				if (teams[i] == tempS)
				{
					if (rCount[i] < 5)
					{
						score[i] += tempI;
						rCount[i]++;
					}
					check = 1;
				}
			}
			//if a team has is not yet in the team vector then add them to the teams and score vector
			if (!check)
			{
				score.push_back(tempI);
				teams.push_back(tempS);
				rCount.push_back(1);
			}
			//reset variables to start over on a new line
			check = 0;
			tab = 0;
			tempS = "";
			inf >> bi;
			tempI = bi;
		}

	}
	inf.close();

	//give the user options to print or export
	cout << "1: Print the results here." << endl;
	cout << "2: Export the results to a text file." << endl;
	cout << "3: Both." << endl;
	cin >> in;

	if (in == 1)
	{
		printScore(score, teams);
	} else if (in == 2)
	{
		exportScore(score, teams);
	} else if (in == 3)
	{
		printScore(score, teams);
		exportScore(score, teams);
	}
}


void printScore(vector<int> score, vector<string> teams)
{
	cout << "Team\t\t\tPoints\n";

	//sorts the teams in order of place (lowest score wins in cross country)
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
	//print out the teams, their place, and their score
	for (int i = 0; i < teams.size(); i++)
	{
		cout << i + 1 << ". " << teams[i] << '\t' << score[i] << '\n';
	}
}

void exportScore(vector<int> score, vector<string> teams)
{
	//set of the output stream
	ofstream outf("results.txt");

	if (!outf)
	{
		cerr << "unable to open file for writing!" << endl;
		exit(1);
	}

	outf << "Team\t\t\tPoints\n";

	//sorts the teams in order of place (lowest score wins in cross country)
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

	//sends out the teams, their place,  and their score to a file
	for (int i = 0; i < teams.size(); i++)
	{
		outf << i + 1 << ". " << teams[i] << '\t' << score[i] << '\n';
	}
}
