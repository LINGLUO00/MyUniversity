#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1.������
//��һ���ص�����
void menu()
{
	printf("**1.�ӷ� 2.����**\n");
	printf("**3.�˷� 4.����**\n"); 
	printf("*****0.exit*****\n"); 

}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;

}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
//void Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("������������:>");
//	scanf("%d %d", &x, &y);
//	ret = (*pf)(x, y);
//	printf("%d\n", ret);
//
//
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("�˳�\n");
//			break;
//		default:
//			printf("�����������������:>\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//������
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int (*pfarr[5])(int, int) = { 0, Add, Sub, Mul, Div };
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		printf("������������:>");
//		scanf("%d %d", &x, &y);
//		ret = pfarr[input](x, y);
//		printf("%d\n", ret);
//	} while (input);
//	return 0;
//}




//2.qsort��ʹ��
//����int����
#include<stdlib.h>
//int cmp_int(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;//Ҫ�ŵ���ֻҪдΪp2-p1�ͺ�
//}
//void print_arr(int arr[], int num)
//{
//	int i = 0;
//	for (i = 0; i < num ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, num, sizeof(arr[0]), cmp_int);
//	print_arr(arr, num);
//	return 0;
//}




//����ṹ��
//#include<string.h>
//struct student
//{
//	char name[20];
//	int age;
//};
//int cmp_age(const void* p1,const void *p2)
//{
//	return ((struct student*)p1)->age - ((struct student*)p2)->age;
//}
//int cmp_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct student*)p1)->name, ((struct student*)p2)->name);
//}
//int main()
//{
//	struct student s[] = {{"z",30},{"l",25},{"w",50}};
//	int num = sizeof(s) / sizeof(s[0]);
//	qsort(s, num, sizeof(s[0]), cmp_age);
//	qsort(s, num, sizeof(s[0]), cmp_name);
//	return 0;
//}



//3.ģ��qsort����ð����ʱ
//void swap(char*buf1, char*buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		int tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//int cmp_int(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;//Ҫ�ŵ���ֻҪдΪp2-p1�ͺ�
//}
//bubble_sort(void* base,size_t num,size_t width,int(*cmp)(const void* p1,const void* p2))
//{
//	size_t i = 0;
// 
//	for (i = 0; i < num - 1; i++)
//	{
//		int flag=1;
//		size_t j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width , (char*)base + (j+1) * width) >0)
//			{
//				flag=0;
//				swap((char*)base + j * width, (char*)base + (j + 1) * width , width);
//			}
//		}
//		if(flag==1)
//		{
//			break;
//		}
//		
//	}
//}
//void print_arr(int arr[], int num)
//{
//	int i = 0;
//	for (i = 0; i < num ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, num, sizeof(arr[0]), cmp_int);
//	print_arr(arr, num);
//	
//	return 0;
//}


