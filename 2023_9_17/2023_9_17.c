#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.��������
//2.�õݹ�ʵ��һ������ֵ��˳�����
//void print(unsigned int num)
//{
//	if (num > 9)
//	{
//		print(num/10);
//	}
//	printf("%d ",num % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	print(num);
//	return 0;
//}

//3.ģ��ʵ��strlen
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str = str + 1;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}
 
 

//4.��������ʱ������ģ��ʵ��strlen
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}


////5.�õݹ�ķ�ʽʵ�ֽ׳�
//int factorial(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * factorial(n - 1);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = factorial(a);
//	printf("%d", ret);
//	return 0;
//}



//6.�õݹ����n��쳲�������
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = Fib(a);
//	printf("%d", ret);
//	return 0;
//}

//7.�õ������n��쳲�������
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = Fib(a);
//	printf("%d", ret);
//	return 0;
//}


