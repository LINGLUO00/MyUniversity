#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//一：友元函数和友元类（不到万不得已不要用友元）
//class Time
//{
//	//友元类声明(说明Data是Time的朋友，Data可以访问Time的私有，但是Time不是Data的友元，Time不可以访问Data的私有）
//	friend class Data;
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//ostream& operator<<(ostream& _cout, const Data& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//class Data
//{
//	//友元函数声明
//	friend ostream& operator<<(ostream& _cout, const Data& d);
//
//public:
//	Data(int year = 2023, int month = 11, int day = 16)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	void SetTimeOfData(int hour, int minute, int second)
//	{
//		//直接访问友元类的私有
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};




//二：内部类（在类里面定义类,内部类不计入大小）
//class A
//{
//public:
//	class B
//	{
//	private:
//		int _b;
//	};
//	void func()
//	{
//		B bb;
//	}
//
//private:
//	int _a;
//};
//int main()
//{
//	A aa;
//
//	A::B bb1;
//	return 0;
//}




//三：编译器优化
int main()
{
	
	return 0;
}






