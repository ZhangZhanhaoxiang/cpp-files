#include <iostream>
using namespace std;
int f(int n)
{
	if (n==1 || n==0) return 1;
	else return f(n-2)+f(n-1);
}
int main()
{
	for (int i=0; i<=20; ++i)
	{
		cout << f(i) << ", ";
	};
	return 0;
}