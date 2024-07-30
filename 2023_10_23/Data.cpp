#define _CRT_SECURE_NO_WARNINGS 1

#include"Data.h"
//分辨月的天数
int Data::GetMonthDay(int year, int month)
{
	const static int MonthArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return MonthArr[month];
}
//构造函数
Data ::Data(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (day<1 || day>GetMonthDay(year, month) ||year < 0 || month < 1 || month>12)
	{
		exit(-1);
	}

}

//printf
void Data::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

//运算符重载
bool Data::operator<(const Data& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Data& Data::operator+=(int day)
{
	//if (day < 0)
	//{
	//	return *this -= day;
	//}
	_day +=day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}