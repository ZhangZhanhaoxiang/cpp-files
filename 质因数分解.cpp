#include <iostream>
using namespace std;
int main()
{
	cout << "max(unsigned long int)=" << numeric_limits<unsigned long int>::max() << ".\n";
	unsigned long int n;
	cout << "Please enter a number:\n";
	cin >> n;
	cout << n << "=";
	for (unsigned long int i = 2; i <= n; ++i)
	{
		while (n != i)
		{
			if (n % i == 0)
			{
				cout << i << "*";
				n = n / i;
			}
			else break;
		};
	};
	cout << n << "\n";
	return 0;
}