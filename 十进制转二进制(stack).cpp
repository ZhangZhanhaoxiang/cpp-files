#include<iostream>
using namespace std;

const int N = 101;	//数组栈的最大长度
int a[N], top = 0;	//定义数组栈和栈顶元素
void push(int);	//入栈push
void pop();	//出栈pop
int getTop();	//获取栈顶元素
void clear();	//清空栈

int main()
{
	int num, cnt = 0;
	cin >> num;
	while (num)
	{
		push(num%2);
		num /=2;
		cnt++;
	}
	for (int i=1; i <= cnt; i++)	//利用栈的LIFO（last in first out）性质倒序输出
	{
		cout << getTop();
		pop();
	}
	return 0;
}

void push(int m)
{
	if (top < N)
		a[++top] = m;
}

void pop()
{
	if (top > 0)
		top--;
}

int getTop()
{
	return a[top];
}

void clear()
{
		top = 0;
}