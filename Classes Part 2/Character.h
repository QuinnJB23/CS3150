//Use this file to hold the class declaration for character

#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include "ObjectPrinter.h"

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
		
		int getHitPoints();
		int getStrength();
		bool isAlive();
		void takeDamage(int);
		
		friend ObjectPrinter::print(Character&);
};

#endif
