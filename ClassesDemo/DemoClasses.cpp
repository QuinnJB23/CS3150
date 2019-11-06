#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 


//class declaration
class Character
{
	private:

	public:
		string name;
		int strength;
		int hitPoints;

		//Character();
		//Character(string name, int strength, int hitPoints):name(name), strength(strength), hitPoints(hitPoints) {cout << "Three arguments." << endl;}
		Character(string name="Bob", int strength=999, int hitPoints=999):name(name), strength(strength), hitPoints(hitPoints) {cout << "Three arguments." << endl;}

		void print()
		{
			cout << name << endl;
			cout << strength << endl;
			cout << hitPoints << endl;

		}

		~Character() {cout << "object destroyed" << endl;}

		//1. create a name, strength, and hitPoints for a character
		//2. create a character in main. Are variables public or private by default?
		//3. create a public section
		//4. create a no argument constructor here and after main
		//5. create a single argument constructor here and after main
		//6. create a print method and test
		//7. comment out the no argument constructor and test
		//8. comment out all constructors here and below
		//9. create constructors using initializer lists
		//10. create a destructor and test
		//11. create a copy constructor and test

		/*
		   A copy constructor is needed when "if an object has pointers or any runtime allocation 
		   of the resource like file handle, a network connection..etc."

		   The default copy constructor only does a shallow copy. User defined copy constructors
		   are needed for deep copies.
		   */

		//12. Create a static variable and associated get function to keep up with the 
		//	  number of characters created. 
		//13. Prepare to fight create functions:take damage, get hit points, get strength, 
		//    is alive 
		//14. Create static fight function that accepts two characters
};

//class driver
int main()
{
	//Character c1 = {"Bob", 6, 100};
	//cout << c1.name;

	Character c1;
	c1.print();
	Character c2("Bob", 5, 100);
	c2.print();
	//cout << c2.name;
}

//class functions

/*Character::Character()
{

	cout << "No argument constructer called.";
	name = "Joe";
	strength = 5;
	hitPoints = 100;
}*/
