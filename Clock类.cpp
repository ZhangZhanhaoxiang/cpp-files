#include <iostream>
using namespace std;

class Clock	//时钟类的定义
{
	public:	//外部接口，公有成员函数
	Clock(int newH, int newM, int newS);	//构造函数
	Clock();	//默认构造函数
	void setTime(int newH = 0, int newM = 0, int setS = 0);
	void showTime();

	private:	//私有成员函数
	int hour, minute, second;
};

//时钟类成员函数的具体实现
//Clock::Clock(): hour(0), minute(0), second(0) {}	//默认构造函数
Clock::Clock(int newH, int newM, int newS): hour(newH), minute(newM), second(newS) {}	//带参数的构造函数
Clock::Clock(): Clock(0, 0, 0) {}	//委托构造函数

void Clock::setTime(int newH, int newM, int newS)
{
	hour = newH;
	minute = newM;
	second = newS;
};

inline void Clock::showTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
};

//主函数
int main()
{
	Clock c(8, 10, 0);	//自动调用构造函数
	Clock c2;	//调用无参数的构造函数
	c.showTime();
	c2.showTime();
	return 0;
}

/*
class 类名 {
public:
类名 (形参);	//构造函数
类名 (const 类名 &对象名);	//复制构造函数

};
类名::类(const 类名 &对象名)	//复制构造函数
{ 函数体 }
*/