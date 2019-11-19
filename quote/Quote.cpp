#include "Quote.h"
#include <iostream>
#include <fstream>

using namespace std;

int Quote::quoteNum = 1;

/*ofstream outf("out.txt");
if (!outf)
{
	cerr << "unable to open file for writing!" << endl;
	exit(1);
}*/


void Quote::add(string q)
{
	quotes[quoteNum] = q;
	quoteNum++;
}

void Quote::remove(int line)
{
	for (int i = line - 1; i < quoteNum; i++)
	{
		quotes[i] = quotes[i+1];
	}
	quotes[quoteNum-1] = "";
	quoteNum--;

	ofstream outf("outt.txt");
	if (!outf)
	{
		cerr << "unable to open file for writing!" << endl;
		exit(1);
	}
	for (int i = 0; i < quoteNum; i++)
	{
		outf << quotes[i] << '\n';
	}
	
}

int Quote::quoteCount()
{
	return quoteNum;
}

string Quote::getQuote(int line)
{
	return quotes[line-1];
}
