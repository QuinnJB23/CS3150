#include <iostream>

using namespace std;

int main()
{

//Here's the code I sent in the email.
//Let's take a closer look.
/*
   unsigned char c = 0x01;
   unsigned char d = 0x0f;
   unsigned char e = 0xff;
   int x =0; 

   x = (int)e;
     cout << x << endl; 
   x += (int)d << 8;
     cout << x << endl; 
   x += (int)c << 16;
     cout << x << endl;
*/

int x = 1; 
//What's this in binary?
x = x << 4;

//What happened?
cout << "x with a left shift of 4 = " << x << endl;

//go back 2
x = x >> 2;
cout << "x with a right shift of 2 = " << x << endl;

//copy the code from above and write out what's happening at each step

}