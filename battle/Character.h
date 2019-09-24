/*
Header file for a generic character
*/

#include<string>
using namespace std;


enum status {dead, alive};
struct character
{
	status state;
	int hitPoints;
	int strength;
	string name;
};

void battle(character c1, character c2);
status statusCheck(character);
