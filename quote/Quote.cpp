#include "Quote.h"
#include <iostream>
#include <fstream>

using namespace std;

int Quote::quoteNum = 0;

/*ofstream outf("out.txt");
if (!outf)
{
	cerr << "unable to open file for writing!" << endl;
	exit(1);
}*/

void Quote::add(string q)
{
	
	//outf << q << '\n';
}

void Quote::remove(int line)
{
	quoteNum--;
}

int Quote::quoteCount()
{
	return quoteNum;
}

string Quote::getQuote(int q)
{
	return quotes[q];
}
