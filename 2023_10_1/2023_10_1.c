#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p = (int*)((int)arr + 4);
//	printf("%x\n", *p);
//	return 0;
//}


//1.���������жϴ�С��
//union un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union un u;
//	u.i = 1;
//	if (u.c == 1)
//	{
//		printf("С��");
//	}
//	else
//	{
//		printf("���");
//	}
//}


//2.void* malloc (size_t num)������Ϊnum���ֽ�
//int main()
//{
//	int* p = (int*)malloc(20);//malloc����ֵΪvoid*
//	if (p == NULL)
//	{
//		perror("�ļ���ʧ��");
//		return 1;
//	}
//	//ʹ��
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//�ͷ�
//	free(p);//Ҫ�ͷ��ĸ��ռ䣬�Ͱ��׵�ַ����free
//	p = NULL;//free�����ÿ�,�ֶ��ÿգ��Է�ֹ��ΪҰָ���p��ʹ��
//
//
//
//	return 0;
//}


//3.void* calloc (size_t num,size_t size)������Ϊnum��size,��malloc��ͬ�ڿ��ٵĿռ�ᱻ��ʼ��Ϊ0
//int main()
//{
//	int i = 0;
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		perror("calloc()");
//		return 1;
//	}	
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//�ͷ�
//	free(p);
//	p = NULL;
//}


//4.void* realloc(void* ptr,size_t size)
int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		perror("malloc()");
		return 1;
	}	
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		*(p + i) = i + 1;
	}
	int* ptr = (int*)realloc(p, 40);//����ʱָ����գ���ֹ����ʧ�ܣ�ԭ����ָ��Ҳ��ʧ
	if (ptr != NULL)
	{
		p = ptr;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i + 1;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	else
	{
		perror("realloc");
		return 1;
	}
	//�ͷ�
	free(p);
	p = NULL;
	return 0;
}


