#include<iostream>
using namespace std;

char str[18] = {' ','.','o','+','=','*','B','O','X','@','%','&','#','/','^','S','E','\0'};
//               0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16 

class Point {
public:
	Point(int n_) {n = n_;}   //构造函数
	Point() {power = 0;}   //默认构造函数
	void pluspower() {++power;}   //权重加1
	void PrintPoint() {cout << str[power];}   //打印该点代表的字符
	void set_n(int n_) {n = n_;}   //设置该点的坐标
	void setpower(int t) {power = t;}   //设置该点的权重，只在第1个和最后1个点使用
private:
	int n, power;
};

void move(int bits, int &n){
	if ((n>=18&&n<=32)||(n>=35&&n<=49)||(n>=52&&n<=66)||(n>=69&&n<=83)||(n>=86&&n<=100)||(n>=103&&n<=117)||(n>=120&&n<=134)) {
		switch(bits)
		{  //M
			case 00: n = n - 18;
			break;
			case 01: n = n - 16;
			break;
			case 10: n = n + 16;
			break;
			case 11: n = n + 18;
			break;
		};
	} else if (n>=1&&n<=15) {
		switch(bits)
		{  //T
			case 00: n = n - 1;
			break;
			case 01: n = n + 1;
			break;
			case 10: n = n + 16;
			break;
			case 11: n = n + 18;
			break;
		};
	} else if (n>=137&&n<=151) {
		switch(bits)
		{  //B
			case 00: n = n - 18;
			break;
			case 01: n = n - 16;
			break;
			case 10: n = n - 1;
			break;
			case 11: n = n + 1;
			break;
		};
	} else if (n==17||n==34||n==51||n==68||n==85||n==102||n==119) {
		switch(bits)
		{  //L
			case 00: n = n - 17;
			break;
			case 01: n = n - 16;
			break;
			case 10: n = n + 17;
			break;
			case 11: n = n + 18;
			break;
		};
	} else if (n==33||n==50||n==67||n==84||n==101||n==118||n==135) {
		switch(bits)
		{  //R
			case 00: n = n - 18;
			break;
			case 01: n = n - 17;
			break;
			case 10: n = n + 16;
			break;
			case 11: n = n + 17;
			break;
		};
	} else if (n==0) {
		switch(bits)
		{  //a
			case 00: break;
			case 01: n = n + 1;
			break;
			case 10: n = n + 17;
			break;
			case 11: n = n + 18;
			break;
		};
	} else if (n==16) {
		switch(bits)
		{  //b
			case 00: n = n - 1;
			break;
			case 01: break;
			case 10: n = n + 16;
			break;
			case 11: n = n + 17;
			break;
		};
	} else if (n==136) {
		switch(bits)
		{  //c
			case 00: n = n - 17;
			break;
			case 01: n = n - 16;
			break;
			case 10: break;
			case 11: n = n + 1;
			break;
		};
	} else if (n==152) {
		switch(bits)
		{  //d
			case 00: n = n - 18;
			break;
			case 01: n = n - 17;
			break;
			case 10: n = n - 1;
			break;
			case 11: break;
		};
	}
}

//	+-----------------+
//	|aTTTTTTTTTTTTTTTb|
//	|LMMMMMMMMMMMMMMMR|
//	|LMMMMMMMMMMMMMMMR|
//	|LMMMMMMMMMMMMMMMR|
//	|LMMMMMMMMMMMMMMMR|
//	|LMMMMMMMMMMMMMMMR|
//	|LMMMMMMMMMMMMMMMR|
//	|LMMMMMMMMMMMMMMMR|
//	|cBBBBBBBBBBBBBBBd|
//	+-----------------+


int main() {
	
	//构造153个点并从0到152设置它们的坐标：
	Point p[153];
	for (int i = 0; i < 153; i++) {
		p[i].set_n(i);
	}
	
	const int SIZE = 16;
	int bits[SIZE];
	cout << "请输入二进制数组：" << endl;
	for (int r = 0; r < SIZE; r++) {
		cin >> bits[r];
	}


	//从76号点开始，对每个点进行坐标变换：
	int position = 76;
	for (int v = 0; v < SIZE; v++) {
		p[position].pluspower();
		move(bits[v], position);
	}

	p[76].setpower(15);
	p[position].setpower(16);

	//按格式打印所有的点：
	cout << "+-----------------+" << endl;
	for (int j = 0; j <= 8; j++) {
		cout << '|';
		for (int m = 0; m <= 16; m++) {
			p[m+17*j].PrintPoint();
		}
		cout << '|' << endl;
	}
	cout << "+-----------------+" << endl;

	return 0;
}