#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<windows.h>
//1.��˸����welcome to scut!!!
//int main()
//{
//	char arr1[] = "welcome to scut!!!" ;
//	char arr2[] = "******************";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		right--;
//		left++;
//	}
//	printf("welcome to scut!!!");
//	return 0;
//}



//2.ģ�����������߼�
//int main()
//{
//	char password[20] = { 0 };
//	int i = 0;
//	int flag = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("���������룺>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			flag = 1;
//			printf("������ȷ\n");
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("��ֹ����");
//	}
//	return 0;
//}


//3. ��������Ϸ
//#include <stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("******************\n");
//	printf("******1.star******\n");
//	printf("******0.exit******\n");
//	printf("******************\n");
//}
//void game()
//{
//	int guess = 0;
//	int ret = rand()%100+1;
//	while (1)
//	{
//		printf("�����֣�");
//		scanf("%d", &guess);
//		if (ret == guess)
//		{
//			printf("��¶���\n");
//			break;
//		}
//		else if (guess > ret)
//		{
//			printf("�´���\n");
//
//		}
//		else
//		{
//			printf("��С��\n");
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((size_t)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("�����������������:\n");
//		}
//
//	} while (input);
//	return 0;
//}



//4.���������Ľϴ�ֵ
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int sup = a > b ? a : b;
//	printf("%d\n", sup);
//	return 0;
//
//}
//int main()
//{
//    int score = 0;
//    int sum = 0;
//    while (scanf("%d", &score) == 1 )
//    {
//        sum += score;
//    }
//    
//    printf("%.1lf\n", sum / 5.0);
//    return 0;
//}
int main()
{
    int score = 0;
    int sum = 0;
    int i = 0;
    while (scanf("%d", &score) == 1 && i < 5)
    {
        i++;
        sum += score;
    }
    double ans = sum / 5.0;
    printf("%.1lf", ans);
    return 0;
}