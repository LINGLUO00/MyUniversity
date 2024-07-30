
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdbool.h>
#include< memory.h >
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void PrintArray(int* a, int n);
void BubbleSort(int* a, int n);
void SelectSort(int* a, int n);
void QuickSort(int* a, int begin, int end);

void Mergesort(int* a, int n);
void MergesortNonR(int* a, int n);

void CountSort(int* a, int n);