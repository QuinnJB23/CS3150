//Quote Generator
//11/16/19
//Jason Quinn
#include "Quote.h"
#include <iostream>
#include <fstream>

using namespace std;

//initialize quoteNum variable to count how many quotes
int Quote::quoteNum = 1;

//adds a quote through user input to the end of the array
void Quote::add(string q)
{
	quotes[quoteNum] = q;
	quoteNum++;
}

//removes a quote on the line given by the user
void Quote::remove(int line)
{
	for (int i = line - 1; i < quoteNum; i++)
	{
		quotes[i] = quotes[i+1];
	}
	quotes[quoteNum-1] = "";
	quoteNum--;	
}

//returns how many total quotes there are
int Quote::quoteCount()
{
	return quoteNum;
}

//gets the quote of the line given by the user
string Quote::getQuote(int line)
{
	return quotes[line-1];
}
