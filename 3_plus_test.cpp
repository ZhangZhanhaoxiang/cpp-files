#include<iostream>
#include<ctime>
using namespace std;

inline int random_i()
{
	srand((unsigned)time(NULL) + (unsigned)rand());
	return rand() % 1000 + 1;
}

bool isright(int a, int b, int c)
{
	if (a + b == c)
		return true;
	else
		return false;
}

int main()
{
	int a, b, c, ans;
	for (int i = 1; i <= 50; ++i)
	{
		a = random_i();
		b = random_i();
		ans = a + b;
		cout << i << ". " << a << " + " << b << " = ";
		cin >> c;
		if (isright(a, b, c))
			cout << "   T" << endl;
		else
			cout << "   F, ans=" << ans << endl;
	}
	return 0;
}