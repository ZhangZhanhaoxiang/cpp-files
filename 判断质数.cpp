#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
 
bool is_prime3(unsigned long long n) { //slow
	for (int i = 2; i < n - 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
 
bool is_prime2(unsigned long long n) { //unknow
	long long stop = sqrt(n) + 1;
	if (n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	for (int i = 3; i <= stop; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
 
bool is_prime(unsigned long long n) { //unknow
	long long stop = n / 6 + 1, Tstop = sqrt(n) + 5;
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
		return false;
	}
	for (int i = 1; i <= stop; i++) {
		if (i * 6 >= Tstop) {break;}
		//cout << i*6+1 << "  " << i*6+5 << endl;
		if ((n % (i * 6 + 1) == 0) || (n % (i * 6 + 5) == 0)) {
			return false;
		}
	}
	return true;
}
 
int main() {
	unsigned long long n;
	int flag;
	clock_t start, end;
	while (true) {
	cout << "number: " << flush;
	cin >> n;
	cout << n << endl;
	bool tmp;
	start = clock();
	flag = is_prime3(n);
	end = clock();
	cout << flag  << "\t" << end - start << "ms\n";
	start = clock();
	tmp = is_prime2(n);
	end = clock();
	if (tmp != flag) {
		flag = -1;
	}
	
	cout << tmp << "\t" << end - start << "ms\n";
	start = clock();
	tmp = is_prime(n);
	end = clock();
	if (tmp != flag) {
		flag = -1;
	}
	
	cout << tmp << "\t" << end - start << "ms\n";
	switch(flag) {
		case -1:
			cout << "UNKNOW" << endl;
			break;
		case 0:
			cout << "NON-PRIME" << endl;
			break;
		case 1:
			cout << "PRIME" << endl;
	}
	
	}
	return 0;
}