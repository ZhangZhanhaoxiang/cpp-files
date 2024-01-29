#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	unsigned short int a, b;
	cout <<
		"Please enter two integers to calculate the greatest common factor and the least common multiple:";
	cin >> a >> b;
	cout << "The greatest common factor: " << gcd(a, b) << ".\n";
	cout << "The least common multiple: " << lcm(a, b) << ".\n";
	return 0;
}