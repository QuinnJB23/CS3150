//Use this file for the functions of objectPrinter

#include <iostream>
#include "Character.h"
#include "ObjectPrinter.h"

using namespace std;

void Character::print(Character c)
{
	cout << "name = " << c.name << endl;
	cout << "strength = " << c.strength << endl;
	cout << "hitPoints = " << c.hitPoints << endl;
}