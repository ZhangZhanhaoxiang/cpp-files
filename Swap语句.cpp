#include <iostream>
using namespace std;
int main()
{
	unsigned short a = 1, b = 2;

	//func 1:
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	//func 2:
	//a = a + b;
	//b = a - b;
	//a = a - b;

	//func 3:
	//a ^= b ^= a ^= b;

	cout << a << " " << b << endl;
	return 0;
}