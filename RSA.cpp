#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/integer/extended_euclidean.hpp>
#include <openssl/bn.h>
using namespace std;

using lint = boost::multiprecision::cpp_int;

lint modP(lint &, lint &, lint &);

int main()
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *bigp = BN_new();
	int digit = 100;
	BN_generate_prime_ex(bigp, digit, 1, nullptr, nullptr, nullptr);
	lint p = boost::multiprecision::cpp_int(BN_bn2dec(bigp));
	BN_generate_prime_ex(bigp, digit, 1, nullptr, nullptr, nullptr);
	lint q = boost::multiprecision::cpp_int(BN_bn2dec(bigp));
	BN_free(bigp);
	BN_CTX_free(ctx);
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;

	lint n = p * q;
	cout << "n = " << n << endl;
	lint phi = (p - 1) * (q - 1);
	lint e = 65537;
	auto r = boost::integer::extended_euclidean(e, phi);
	lint d = r.x;
	for (int i = 1; d <= 10; i++) {
		d += i * phi;
	}
	cout << "d = " << d << endl;
	lint M{ 0 };
	cout << "输入明文: " << endl;
	cin >> M;
	lint C = modP(M, e, n);
	cout << "C = " << C << endl;
	lint M_ = modP(C, d, n);
	cout << "M_ = " << M_ << endl;



	return 0;
}


lint modP(lint &b, lint &e, lint &m)
{
	lint ans = 1;
	b %= m;
	while (e > 0) {
		if (e % 2 == 1) {
			ans = (ans * b) % m;
		}
		b = (b * b) % m;
		e /= 2;
	}
	return ans;
}