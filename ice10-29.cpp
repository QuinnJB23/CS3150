#include <iostream>
#include <iomanip> //io manipulators
#include <sstream> //string streams
#include <fstream> //file io

using namespace std;

int main()
{

	unsigned char b = 0xff;

	ifstream inf("1_Created.bmp");
 	
	if (!inf)
	{cerr <<"unable to open file for writing!" << endl; exit(1);}
 	
	
	
	
	for (int i = 0; i < 2; i++)
	{
		inf >> b;
		cout << hex << +b << '\n';
			
	}
		

   	
	inf.close();
		
	return 0;
}