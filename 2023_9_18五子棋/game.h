#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
//��������ͷ�ļ�
#include <string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//��������
void Initboard(char board[ROW][COL], int row ,int col);
//��ӡ����
void Displayboard(char board[ROW][COL], int row , int col);
//�������
void Playermove(char board[ROW][COL], int row, int col);
//��������
void Computermove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
int Iswin(char board[ROW][COL], int row, int col);