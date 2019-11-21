#include <iostream>

using namespace std;

int a(){return 3;}
int b(){return 4;}
int c(){return 5;}


int main ()
{
int x = (a(),b(),c());
cout << x << endl;

if(cin>>x,x*=2,x<8)
	cout << "true" << endl;
else
	cout << "false" << endl;


}