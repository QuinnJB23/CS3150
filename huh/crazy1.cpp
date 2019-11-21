#include <iostream>

using namespace std;

int main ()
{
int x = 10;
int y = 010;
int z = 0x10;

cout << "x + y = " << x+y << endl;
cout << "z + 1 = " << z + 1 << endl;
cout << "++x ++y ++z " << ++x << " " << ++y << " " << ++z << endl;
}