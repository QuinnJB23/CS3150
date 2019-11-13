//Use this file to hold the methods of Character

#include "Character.h"
#include <iostream>

using namespace std;

int Character::charNum =0; 

void Character::print()
{
	cout << "name = " << name << endl;
	cout << "strength = " << strength << endl;
	cout << "hitPoints = " << hitPoints << endl;
}


int Character::getHitPoints(){return hitPoints;}
int Character::getStrength(){return Strength;}
bool Character::isAlive(){return status;}
void Character::takeDamage(int damage){hitPoints -= damage;}


