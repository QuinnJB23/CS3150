//Keep in mind that classes will only know about things that have come before.
//Also remember what prototyping is. 
//Make the following code work without errors and be prepared to explain why it didn't work.
//Hint I removed 4 lines
//I edited 1 line

#include <iostream>

using namespace std;
 
class B;

class A
{
	private:
		int a_thing;
	public: 
		A(){a_thing=0;}
		A(B b);
		
		friend class B;

};

class B
{
	private:
		int b_thing;
	public: 
		B(){b_thing=0;}
		B(A a){a.a_thing= 0; b_thing=0;}
		
		friend class A;
};

A::A(B b){a_thing=0; b.b_thing=0;}

int main()
{
	A a;
	B b(a);
}
