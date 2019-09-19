#include<iostream>
#include<cstdlib>//needed for rand function
#include<ctime>//needed for clock generated seed

using namespace std;

int main()
{
	//1. 
	//Generate pseduo-random numbers
	/*
	   cout << "run 1" <<endl;
	   for (int i=0; i<8; i++)
	   cout << rand()<<endl;

	   cout << endl << "run 2" << endl;
	   for (int i=0; i<8; i++)
	   cout << rand()<<endl;

	// Are these numbers the same?
	// Why?
	// What happened during your run?

	srand(56);

	cout << endl << "run 3" <<endl;
	for (int i=0; i<8; i++)
	cout << rand()<<endl;

	//What happens if you run your program twice?
	//What can we assume from all of this?

	//seed it with the clock and run twice
	*/

	/*	cout << time(NULL);

		srand(time(NULL));

		cout << endl << "run 4" <<endl;
		for (int i=0; i<8; i++)
		cout << rand() <<endl;
		*/
	//Does run 4 change? How much?



	//1. Create int max random numbers from 1 - 100 
	//2. Save the number of occurrences of each number in an int array. 
	//3. Output the percentage of occurrences of each random number. 
	//4. Try it with the seeds presented above and see how the results differ. 

	int a[10];
	int r;

	for (int i = 0; i < INT_MAX; i++) {
		r = rand() % 10;
		a[r]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
