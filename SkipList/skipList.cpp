#define _CRT_SECURE_NO_WARNINGS 1
#include"skipList.h"
int main()
{
	Skiplist sl;
	//int a[] = { 5, 2, 3, 8, 9, 6, 5, 2, 3, 8, 9, 6, 5, 2, 3, 8, 9, 6 };
	int a[] = { 5, 2, 3, 8, 9, 6 };
	for (auto e : a)
	{
		//sl.Print();
		//printf("--------------------------------------\n");

		sl.add(e);
	}
	sl.Print();

	int x;
	cin >> x;
	sl.erase(x);

	return 0;
}