#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//1.ģ��ʵ��strcpy
//char* my_strcpy(char* tar, const char* base)
//{
//	char* ret = tar;
//	assert(tar && base);
//	while (*tar++ = *base++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "hehe";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	//Ҳ����дprintf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}


//2.ģ��ʵ��strcat
//char* my_strcat(char* tar, const char* base)
//{
//	char* ret = tar;
//	while (*tar != '\0')
//	{
//		tar++;
//	}
//	while (*tar++ = *base++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


////3.ģ��ʵ��strstr
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cp = (char*)str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 =(char*) str2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//
//
//}
//int main()
//{
//	char arr1[] = "abcdebcdf";
//	char arr2[] = "bcd";
//	char* p = my_strstr(arr1, arr2);
//	if (p == NULL)
//	{
//		printf("�Ҳ���");
//	}
//	else
//	{
//		printf("�ҵ���");
//	}
//}


//4.strtok
//#include<string.h>
//int main()
//{
//	char arr1[] = "192.zwp@com";
//	char buf[30] = { 0 };
//	strcpy(buf, arr1);
//	const char* p = "@.";
//	char* str = NULL;
//	for (str = strtok(buf, p); str != NULL; str = strtok(NULL, p))
//	{
//		printf("%s\n", str);
//	}
//	return 0;
//}

//5.strerror
//#include<errno.h>
//#include<string.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("��ʧ�ܣ�ԭ����: %s\n", strerror(errno));
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//6.perror�൱��printf+strerror,���Զ����Զ������ݺ����ð�ţ�����ӡ������Ϣ
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("�����:");
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//7.memcpy�ڴ濽��
//#include<string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[20] = { 0 };
//	memcpy(arr2, arr1, 20);//��λ�ֽ�
//	return 0;
//}


//8.ģ��ʵ��memcopy
//#include<assert.h>
//void* my_memcpy(void* tar, const void* base, size_t sz)
//{
//	assert(tar && base);
//	char* ret = (char*)tar;
//	while (sz--)
//	{
//		*(char*)tar = *(char*)base;
//		base = (char*)base + 1;
//		tar = (char*)tar + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1, 20);//��λ�ֽ�
//	return 0;
//}


//9.memmove����ʵ���ص����������⸲��
//#include<string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	memmove(arr1+2 , arr1, 8);//��λ�ֽ�
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}


//10.ģ��ʵ��memmove
//���base��tar��ߣ��Ӻ���ǰ��������֮����ǰ���󿽱�
//void* my_memmove(void* tar, void* base, size_t num)
//{
//	assert(tar && base);
//	void* ret = tar;
//	if (tar < base)
//	{
//		*(char*)tar = *(char*)base;
//		base = (char*)base + 1;
//		tar = (char*)tar + 1;
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char*)tar + num) = *((char*)base + num);
//
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	my_memmove(arr1 + 2, arr1, 8);//��λ�ֽ�
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}


////11.memcmp�ڴ�Ƚ�
//#include<string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,4,6 };
//	int ret = memcmp(arr1, arr2, 16);
//	printf("%d\n", ret);
//	return 0;
//}


//12.memset
//#include<string.h>
//int main()
//{
//	//int arr[10] = { 0 };
//	//memset(arr, 1, sizeof(arr[0]));//���ֽ�Ϊ��λ����,����������
//	//int i = 0;
//	//for (i = 0; i < 5; i++)
//	//{
//	//	printf("%d ", arr[i]);
//	//}
//	char arr[] = "hello world";
//	memset(arr, 'x', 5);//����ǰ5���ֽ�����Ϊ��x'
//	printf("%s\n", arr);
//	return 0;
//}


//13.�ṹ����������(��ָ��
//struct node
//{
//	int data;
//	struct node* next;
//};
//int main()
//{
//	struct node n1;
//	struct node n2;
//	n1.next = &n2;
//	return 0;
//}


//typedef���������������ṹ��
//typedef struct
//{
//	int data;
//} s ;


