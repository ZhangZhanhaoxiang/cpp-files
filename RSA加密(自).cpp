#include<iostream>
using namespace std;

int gcd(int, int);
bool isPrime(int);
void printPrimes();
int countPowMod(int, int, int);

int main()
{
	printPrimes();
	cout << "请从以上质数中选择2个：" << endl;
	unsigned short p, q;
	cin >> p >> q;
	unsigned int n = p * q, fhi = (p - 1) * (q - 1);
	cout << "请再从以上质数中选择1个大于" << ((p > q) ? p : q) << "的：" << endl;
	unsigned short e;
	cin >> e;
	unsigned long d = 1;
	while(e * d % fhi != 1)
		d++;
	cout << "公钥：（" << e << "，" << n << "）；" << endl;
	cout << "私钥：（" << d << "，" << n << "）. " << endl;
	int m, c, m_;
	cout << "请输入明文m：" << endl;
	cin >> m;
	c = countPowMod(m, e, n);
	cout << "密文c = " << c << endl;
	m_ = countPowMod(c, d, n);
	cout << "解密后的明文m_ = " << m_ << endl;
	return 0;
}

int gcd(int a, int b)
{
	if (a < b)
		a ^= b ^= a ^= b;
	return (b == 0) ? a : gcd(b, a % b);
}

bool isPrime(int n)
{
	bool isPrime = 1;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			isPrime = 0;
			break;
		}
	}
	return isPrime;
}

void printPrimes()
{
	cout << "以下为所有三位数质数：" << endl;
	int numbers[901];
	for (int i = 0; i < 901; i++)
		numbers[i] = i + 101;
	for (int i = 0; i < 901; i++)
	{
		if (isPrime(numbers[i]))
			cout << numbers[i] << " ";
	}
	cout << endl;
}

int countPowMod(int a, int power, int mod)
{
   int result = 1;
   int temp = a % mod;
   while (power >= 1) {
      if (power % 2 != 0) {
         result = (result * temp) % mod;   
      }
      temp = (temp * temp) % mod;
      power /= 2;   
   }
   return result;
}