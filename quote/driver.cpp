//Quote Generator
//11/16/19
//Jason Quinn
#include <iostream>
#include <fstream>
#include <ctime>
#include "Quote.h"

using namespace std;

//Get command line arguments
int main(int argc, char** argv)
{
	//initialize variables
	string filename = "";
	int choice;
	bool check = 0;
	string q;
	int r;
	//set random seed
	srand(time(0));

	//if filename is given through command line arguments then print random quote from that file
	if (argc > 1)
	{

		filename = argv[1];
		Quote q1(filename);
		r = rand() % q1.quoteNum;
		cout << q1.getQuote(r);

		exit(0);
	} 

	//if no command line arguments are given then ask for filename
	cout << "Please enter a filename: ";
	cin >> filename;

	Quote q1;


	//print out and execute these six options until the user selects to exit
	while (check == 0)
	{
		cout << "Please choose one of the following actions by entering the corresponding number." << endl;
		cout << "1. Get random quote." << endl;
		cout << "2. Add quote." << endl;
		cout << "3. Remove quote by line." << endl;
		cout << "4. Get specific quote by line." << endl;
		cout << "5. Get number of current quotes." << endl;
		cout << "6. Exit." << endl;
		cin >> choice;

		if (choice == 1)
		{
			r = rand() % q1.quoteNum + 1;
			cout << q1.getQuote(r) << endl;
		} else if (choice == 2)
		{
			cout << "Please type the quote you would like to add." << endl;
			getline(cin >> ws, q);
			q1.add(q);

		} else if (choice == 3)
		{
			int line;
			cout << "Please enter the line number you would like to remove." << endl;
			cin >> line;
			q1.remove(line);

		} else if (choice == 4)
		{
			int line;
			cout << "Please enter the line number of which line you would like to see the quote." << endl;
			cin >> line;
			cout << q1.getQuote(line) << endl;

		} else if (choice == 5)
		{
			cout << "There are " << q1.quoteCount() << " quotes." << endl;

		} else if (choice == 6)
		{
			check = 1;
		} else
		{
			cout << "Invalid entry. Please enter a number between 1 and 6." << endl;
			exit(1);
		}
	}
}
