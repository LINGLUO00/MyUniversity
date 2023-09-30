#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<windows.h>
//1.闪烁输入welcome to scut!!!
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



//2.模拟输入密码逻辑
//int main()
//{
//	char password[20] = { 0 };
//	int i = 0;
//	int flag = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			flag = 1;
//			printf("密码正确\n");
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("终止密码");
//	}
//	return 0;
//}


//3. 猜数字游戏
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
//		printf("猜数字：");
//		scanf("%d", &guess);
//		if (ret == guess)
//		{
//			printf("你猜对了\n");
//			break;
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了\n");
//
//		}
//		else
//		{
//			printf("猜小了\n");
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
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误，请重新输入:\n");
//		}
//
//	} while (input);
//	return 0;
//}



//4.求两个数的较大值
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