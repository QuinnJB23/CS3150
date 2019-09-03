//Basic  Structure Demonstation File
//8/28/19
//Dr. G
//Edited by Jason Quinn

//Preprocessor directives
#include <iostream>

//Defining namespace
using namespace std;


//main function
int main()
	{
	
	//1. Declare an int variable x
	
	/*
	Ways to initialize: 
	int x, y; 
	int x = 0;
	int x(0);
	int x{};
	int x{4};
	
	What is direct vs indirect assignment?
	What happens behind the scenes when you declare a variable?
	What happens if you don't initialize a variable?
	*/

	int x = 0;
	//2. Prompt the user for an integer value
	
	cout << "Give me an integer please\n";
	/*
	What does cout stand for?
	What is the difference in endl and \n?
	What is the << called and what does it do?
	*/
	
	
	//3. Save that input into a variable
	
	cin >> x;

	cout << "you entered a " << x;
	/*
	What does cin stand for?
	What's a common mistake with cin and cout?
	*/
	
	//4. Print that variable and that variable + 10
	
	return 0;
	}
