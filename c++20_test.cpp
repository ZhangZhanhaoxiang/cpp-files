#include<iostream>
using namespace std;

// std=c++20
void f(auto a)
{
	cout << a << endl;
}

int main()
{
	int a=1;
	float b=2.0;
	char c='3';
	bool d=false;
	f(a);
	f(b);
	f(c);
	f(d);
	return 0;
}