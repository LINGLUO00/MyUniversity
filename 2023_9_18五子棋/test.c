#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("**********************\n");
	printf("********1.star********\n");
	printf("********0.exit********\n");
	printf("**********************\n");
}
void game()
{
	//���������Ҫһ����ά����
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ʾ����
	Displayboard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//�������
		Playermove(board, ROW, COL);
		//��ӡ����
		Displayboard(board, ROW, COL);
		// �ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		Computermove(board, ROW, COL);
		//��ӡ����
		Displayboard(board, ROW, COL);
		// �ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if ('*' == ret)
	{
		printf("��Ӯ��\n");
	}
	else if ('#' == ret)
	{
		printf("������\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int )time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ���������ѡ��:>");
			break;

		}
	} while (input);
	return 0;
}