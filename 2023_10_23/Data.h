#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
using namespace std;

class Data
{
public:
	int GetMonthDay(int year, int month);
	Data(int year = 1, int month = 1, int day = 1);
	void Print() const;
	bool operator<(const Data& d);
	bool operator==(const Data& d);
	bool operator>(const Data& d);
	Data& operator+=(int day);
	/*Data& operator-=(int day);*/





private:
	int _year;
	int _month;
	int _day;
};