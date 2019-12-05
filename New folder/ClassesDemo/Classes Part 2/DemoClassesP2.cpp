//1. Examine the below code and be prepared to explain what it does
//2. Answer any questions included in code comments
//3. Implement the commented out methods.
//What's the difference in a function and a method?
//4. Move the Character class out into it's own file(s)
//What should go in a header and what should go in a cpp file as far as classes?
//5. Create a separate class called ObjectPrinter and move the print method there?
//6. Explore making objectPrinter a friend class and/or the print method as a friend method.


#include <iostream>

using namespace std; 


class Character
{
	private: 
		string name;
		int strength;
		int hitPoints;
		enum STATUS {ALIVE, DEAD};
		STATUS status;
		
	public: 
	
		//How many different types of constructors will this allow for?
		Character(string name = "John Doe", int strength=1, int hitPoints=1): 
			name(name), strength(strength), hitPoints(hitPoints){charNum++; status=ALIVE;}

		~Character(){cout << "Object destroyed " << endl;}
	
		//What is the purpose of making this variable static?
		static int charNum;

		void print();
		
		//int getHitPoints();
		//int getStrength();
		//bool isAlive();
		//void takeDamage(int);
};

//Why is this here outside the class?
int Character::charNum =0; 

void Character::print()
{
	cout << "name = " << name << endl;
	cout << "strength = " << strength << endl;
	cout << "hitPoints = " << hitPoints << endl;
}


int main()
{
	Character c1;
	Character c2("Bob the plumber", 56, 100);
	c1.print();
	c2.print();

	cout << Character::charNum <<endl;
}




