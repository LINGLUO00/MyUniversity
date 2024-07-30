#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}Stack;

void Init(int* a);