#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//求多个连续阶乘的和
int main()
{
	int n = 3;
	int i = 0;
	int ret = 1;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}