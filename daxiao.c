#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
//1�������鳤��
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr[0]));
//	int sz = 0;
//	printf("%d\n", sz = sizeof(arr) / sizeof(arr[0]));

//2define�����
//#define ADD(X,Y)X+Y
//int main ()
//{
//	printf("%d\n", 4 * (ADD(3, 2)));
//
//
//
//	return 0;
//}




//3���뺯��
//int  sum(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d,%d", &x, &y);
//	int m=sum(x, y);
//	printf("%d\n", m);
//
//
//	return 0;
//}



//4��while��������
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int i = 0;
//	while(i<=4)
//	{
//		printf("%d\n", arr[i]);
//		i++;
//
//
//	}
//
//
//
//	return 0;
//}



//5.3000��������Ҹ��ù���
//int main()
//{
//	int line = 1;
//	while (line <= 3000)
//	{
//		printf("д���룺%d\n", line);
//		line++;
//
//	}
//	if (line >= 3000)
//	{
//		printf("�ù���\n");
//
//	}
//
//
//	return 0;
//}



//6.�ܲ����ҵ��ù���
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	if (input >= 3000)
//	{
//		printf("�ù���\n");
//
//	}
//	else
//	{
//		printf("����Ŭ��\n");
//
//	}
//
//
//
//	return 0;
//}



//7.enumö�ٳ���
//



//8.const���γ�����
//int main()
//{
//	const int num = 10;
//	//num=20���ܰ�num�ģ�����
//	printf("numΪ%d\n", num);
//
//
//	return 0;
//}


//9.��������extern
//extern int go_vs;
//int main()
//{
//	printf("%d\n", go_vs);
//
//
//	return 0;
//}


//10.ǿ������ת��
//int main()
//{
//	int  a = (int)3.14;
//	printf("%d\n", a);
//
//
//	return 0;
//}


//11.��ӡ����Ϊ1������Ϊ||��Ϊ��ֻ�ῴ||ǰ��Ϊ��ʹ�ӡ1
//int main()
//{
//	int a = 3;
//	int b = 2;
//
//	int c = a || b;
//
//	printf("%d\n", c);
//
//	return 0;
//}
//


//12.��Ŀ������
//int main()
//{
//	int max = 0;
//	int a = 0;
//	int b = 0;
//	scanf("%d,%d", &a, &b);
//	max = a > b ? a : b;
//	printf("����ǣ�%d\n", max);
//
//
//	return 0;
//}


//13.����/Ƶ����ʹ�õ����ݣ�����ڼĴ����У�����Ч��
//int main()
//{
//	register int num = 100;
//
//
//	return 0;
//}



//14.��д��������

//typedef unsigned int u_int;
//
//
//int main()
//{
//	u_int num = 0;
//	printf("%d\n", num);
//
//	return 0;
//}

//15.stadic�����ֲ�����ֵ
//




//16.�����ò���
//int main()
//{
//	int a = 45;
//	int* p = &a;
//	*p = 79;
//	printf("%d\n", *p);
//
//
//
//
//	return 0;
//}


//17.struct�����Զ���ṹ����
//struct STU
//{
//	//��Ա
//	char name[20];
//	int age;
//	double  high;
//
//
//};
//
//int main()
//{
//	//��ʼ����Ա
//	struct STU s = { "С��",20,1.68 };
//	printf("%s,%d,%lf\n", s.name, s.age, s.high);
//	struct STU* p = &s;
//	printf("%s,%d,%lf\n", (*p).name, (*p).age, (*p).high);
//	printf("%s,%d,%lf\n", p->name, p->age, p->high);
//
//	return 0;
//}

//18.�����