#define _CRT_SECURE_NO_WARNINGS 1

#include"Data.h"



int main()
{
	Data d1(2023, 10, 23);
	Data d2(d1);
	Data d3(2023, 10, 24);
	d1.Print();
	d2.Print();
	d3.Print();
	if (d2 < d3)
	{
		cout << "d2<d3" << endl;
	}
	else
	{
		cout << "d2>d3" << endl;
	}

	d2 += 20;
	d2.Print();
	return 0;
}