/*

Battle sequence in class exercise
9 - 18 - 2019
Dr. G

*/

#include <iostream>
#include "Character.h"

using namespace std;

int main()
{
	typedef character hero;
	typedef character badGuy;

	badGuy b1;
	hero h1;

	b1.state = alive;
	h1.state = alive;

	b1.hitPoints = 10;
	h1.hitPoints = 10;

	b1.strength = 3;
	h1.strength = 2;	

	b1.name = "Bad guy";
	h1.name = "Hero";

	battle(b1, h1);
}

//1. In Character.h create a character struct that can hold at least a status, hitPoints, and a strength value
//2. Create a enum status that will allow for a status of alive or dead
//3. Typdef a hero and a bad guy as character structs
//4. Create a badguy and a hero in main using the created typdef and send them to battle in the battle function in Character
//5. Battle as long as no one is dead
//6. Generate a hit value with a random number from 1 to strength
//7. Create a battleNum variable that resides in Character.cpp that keeps track with the number of battles fought, but allow Driver to access it
