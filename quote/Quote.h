//Quote Generator
//11/16/19
//Jason Quinn
#ifndef QUOTE
#define QUOTE

#include <iostream>
#include <fstream>

using namespace std;

class Quote
{
	//private variable declaration
	private:
		string filename;
		string quotes[10000];


	public:
		//constructor that will work with no arguments or one argument
		Quote(string filename="Quotes.txt"):filename(filename)
		{
			ifstream inf(filename);
			if (!inf)
			{
				cerr << "unable to open file for reading!" << endl;
				exit(1);
			}
			char temp;
			while (inf.get(temp))
			{
				if (temp == '\n')
				{
					quoteNum++;
				}
			}
			ifstream in(filename);
			if (!in)
			{
				cerr << "unable to open file for reading!" << endl;
				exit(1);
			}

			for (int i = 0; i < quoteNum; i++)
			{
				quotes[i] = "";

				while (in.get(temp))
				{
					if (temp != '\n')
					{
						quotes[i] += temp;
					} else
					{
						break;
					}
					
				}
			}

		}


		//destroys the class when it isn't used anymore
		~Quote(){}

		//declare quoteNum variable
		static int quoteNum;

		//declare the class methods
		void add(string);
		void remove(int);
		int quoteCount();
		string getQuote(int);


};

#endif
