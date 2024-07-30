#define _CRT_SECURE_NO_WARNINGS 1
//�ѵ�����Ӧ�ã�������
//				topk����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
#pragma once
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php , HPDataType x);
void HeapPop(HP* php);
void AdjustDown(int* a, int n, int parent);
void AdjustUp(HPDataType* a, int child);
bool HeapEmpty(HP* php);
void HeapFree(HP* php);
