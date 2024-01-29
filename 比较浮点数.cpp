#include <iostream>
using namespace std;

float abs(float a)
{
	if (a >= 0) return a;
	else return -a;
}

int main()
{
	float a, b;
	cin >> a >> b;
	if (abs(a - b) < 1e-5) cout << a << " == " << b << endl;
	else cout << a << " != " << b << endl;
	return 0;
}