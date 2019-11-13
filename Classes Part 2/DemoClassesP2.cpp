//1. Examine the below code and be prepared to explain what it does
//2. Answer any questions included in code comments
//3. Implement the commented out methods.
//What's the difference in a function and a method?
//4. Move the Character class out into it's own file(s)
//What should go in a header and what should go in a cpp file as far as classes?
//5. Create a separate class called ObjectPrinter and move the print method there?
//6. Explore making objectPrinter a friend class and/or the print method as a friend method.


#include <iostream>
#include "Character.h"

using namespace std; 


int main()
{
	Character c1;
	Character c2("Bob the plumber", 56, 100);
	c1.print();
	c2.print();
	ObjectPrinter::print(c1);
	ObjectPrinter::print(c2);

	cout << Character::charNum <<endl;
}




