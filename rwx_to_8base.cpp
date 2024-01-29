#include<iostream>
using namespace std;

char c[9];
int n[3];
void modeOne();
//void modeTwo();

int main()
{
	modeOne();
	//modeTwo();
	return 0;
}

void modeOne()
{
	cout << "Please enter the 9-digit RWX permission string that you want to convert to 3 octal digits: ";
	for (char &x : c)
		cin.get(x);
	cout << endl;
	for (int i=0; i<9; ++i)
	{
		switch (*(c+i))
		{
			case 'r':
				n[i/3]+=4;
				break;
			case 'w':
				n[i/3]+=2;
				break;
			case 'x':
				n[i/3]+=1;
				break;
		}
	}

	for (int x : n)
		cout << x;
	cout << endl;
}
/*
void modeTwo()
{
	for (int &x : n)
		cin.get(x);
	cout << endl;
	for (int i=0; i<9; ++i)
	{
		switch (*(n+i/3))
		{
			case 0:
				*(c+i/3)='---';
				break;
			case 1:
				*(c+i/3)='--x';
				break;
			case 2:
				*(c+i/3)='-w-';
				break;
			case 3:
				*(c+i/3)='-wx';
				break;
			case 4:
				*(c+i/3)='r--';
				break;
			case 5:
				*(c+i/3)='r-x';
				break;
			case 6:
				*(c+i/3)='rw-';
				break;
			case 7:
				*(c+i/3)='rwx';
				break;
		}
	}
	for (char x : c)
		cout << x;
	cout << endl;
}
*/
