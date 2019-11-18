#ifndef QUOTE
#define QUOTE

#include <iostream>

using namespace std;

class Quote
{
	private:
		string filename;
		string file[];


	public:
		void add(string);
		string remove(int);
		int quoteCount();
		string getQuote(int);



		~Quote(){cout << "Object destroyed " << endl;}


};

#endif
