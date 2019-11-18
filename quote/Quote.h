#ifndef QUOTE
#define QUOTE

#include <iostream>
#include <fstream>

using namespace std;

class Quote
{
	private:
		string filename;
		string quotes[1000];


	public:
		Quote(string filename):filename("Quotes.txt")
		{
			cout << "Constructor called!" << endl;
			ifstream inf(filename);
			if (!inf)
			{
				cerr << "unable to open file for reading!" << endl;
				exit(1);
			}
			ofstream outf("out.txt");
			if (!outf)
			{
				cerr << "unable to open file for writing!" << endl;
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
						outf << temp;
					} else
					{
						outf << temp;
						break;
					}
					
				}
			}

		}


		~Quote(){cout << "Object destroyed " << endl;}

		static int quoteNum;

		void add(string);
		void remove(int);
		int quoteCount();
		string getQuote(int);


};

#endif