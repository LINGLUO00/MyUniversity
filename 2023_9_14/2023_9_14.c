#define _CRT_SECURE_NO_WARNINGS 1
//1.��߷�����ͷ�֮��
#include <stdio.h>
//int main()
//{
//    int MAX = 0;
//    int MIN = 100;
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int m = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &m);
//        if (m < MIN)
//        {
//            MIN = m;
//        }
//        if (m > MAX)
//        {
//            MAX = m;
//        }
//    }
//    printf("%d", MAX - MIN);
//
//    return 0;
//}

//2.��ӡ100����3�ı�������
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//3.���������������Ӵ�С���
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a=b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}


//4.��ӡ100~200֮�������(һ���ܹ��ֽ������i��һ����һ������С�ڵ���sqrt(i),���Բ���2-i,ֱ��2-sqrt(i),�����ҵ�����һ������
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100;  i <= 200; i++)
//	{
//		int flag = 1;
//		//�жϣ���2��i-1������ȥ�Գ�i
//		int j = 0;
//		for (j = 2; j < i ; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//
//		}
//		if (flag == 1)
//		{
//			count++;
//			printf("%d\n", i);
//			
//		}
//	}
//	printf("count=%d\n", count);
//	return 0;
//}
//�ú���дһ��


//5.��ӡ1000�굽2000��֮�������
//int is_year(int y)
//{
//
//	return ((y % 4 == 0 && y % 100 != 0) || (y & 400 == 0));
//}
//int main()
//{
//	int y = 0;
//	int count = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (is_year(y) == 1)
//		{
//			count++;
//			printf("%d ", y);
//		}
//
//	}
//	printf("\n%d\n", count);
//	return 0;
//}