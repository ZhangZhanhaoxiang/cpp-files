#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	const int maxValue = 1;
	const int minValue = 0;
	for (int i = 0; i <= 63; i++)
	{
		for (int j = 0; j <= 1; j++) {
		int a = (rand() % (maxValue - minValue + 1)) + minValue;
		cout << a;
		}
		cout << " ";
	}
	return 0;
}