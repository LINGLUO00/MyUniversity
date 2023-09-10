#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
//1测量数组长度
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr[0]));
//	int sz = 0;
//	printf("%d\n", sz = sizeof(arr) / sizeof(arr[0]));

//2define定义宏
//#define ADD(X,Y)X+Y
//int main ()
//{
//	printf("%d\n", 4 * (ADD(3, 2)));
//
//
//
//	return 0;
//}




//3输入函数
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



//4用while遍历数组
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



//5.3000代码可以找个好工作
//int main()
//{
//	int line = 1;
//	while (line <= 3000)
//	{
//		printf("写代码：%d\n", line);
//		line++;
//
//	}
//	if (line >= 3000)
//	{
//		printf("好工作\n");
//
//	}
//
//
//	return 0;
//}



//6.能不能找到好工作
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	if (input >= 3000)
//	{
//		printf("好工作\n");
//
//	}
//	else
//	{
//		printf("继续努力\n");
//
//	}
//
//
//
//	return 0;
//}



//7.enum枚举常量
//



//8.const修饰常变量
//int main()
//{
//	const int num = 10;
//	//num=20不能把num改，报错
//	printf("num为%d\n", num);
//
//
//	return 0;
//}


//9.声明变量extern
//extern int go_vs;
//int main()
//{
//	printf("%d\n", go_vs);
//
//
//	return 0;
//}


//10.强制类型转换
//int main()
//{
//	int  a = (int)3.14;
//	printf("%d\n", a);
//
//
//	return 0;
//}


//11.打印出来为1，是因为||，为或，只会看||前，为真就打印1
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


//12.三目操作符
//int main()
//{
//	int max = 0;
//	int a = 0;
//	int b = 0;
//	scanf("%d,%d", &a, &b);
//	max = a > b ? a : b;
//	printf("最大是：%d\n", max);
//
//
//	return 0;
//}


//13.大量/频繁被使用的数据，想放在寄存器中，提升效率
//int main()
//{
//	register int num = 100;
//
//
//	return 0;
//}



//14.简写数据类型

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

//15.stadic保留局部变量值
//




//16.解引用操作
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


//17.struct创建自定义结构类型
//struct STU
//{
//	//成员
//	char name[20];
//	int age;
//	double  high;
//
//
//};
//
//int main()
//{
//	//初始化成员
//	struct STU s = { "小三",20,1.68 };
//	printf("%s,%d,%lf\n", s.name, s.age, s.high);
//	struct STU* p = &s;
//	printf("%s,%d,%lf\n", (*p).name, (*p).age, (*p).high);
//	printf("%s,%d,%lf\n", p->name, p->age, p->high);
//
//	return 0;
//}

//18.求最大