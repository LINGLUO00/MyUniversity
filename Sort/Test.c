
#include"Sort.h"
#include "Stack.h"





void TestInsertSort()
{
	int a1[] = { 4,7,1,9,3,4,5,8,3,2 };
	PrintArray(a1, sizeof(a1) / sizeof(a1[0]));
	InsertSort(a1, sizeof(a1) / sizeof(a1[0]));
	PrintArray(a1, sizeof(a1) / sizeof(a1[0]));
}



void TestSellSort()
{
	int a2[] = { 4,7,1,9,3,4,5,8,3,2 };
	ShellSort(a2, sizeof(a2) / sizeof(a2[0]));
	PrintArray(a2, sizeof(a2) / sizeof(a2[0]));
}

void TestBubbleSort()
{
	int a3[] = { 4,7,1,9,3,4,5,8,3,2 };
	ShellSort(a3, sizeof(a3) / sizeof(a3[0]));
	PrintArray(a3, sizeof(a3) / sizeof(a3[0]));
}


void TestSelectSort()
{
	/*int a4[] = { 4,7,1,9,3,4,5,8,3,2 };*/
	int a4[] = { 9,7,1,3,3,0,5,8,3,2,3 };
	SelectSort(a4,sizeof(a4) / sizeof(a4[0]));
	PrintArray(a4, sizeof(a4) / sizeof(a4[0]));
}



void TestQuickSort()
{
	int a5[] = { 4,10,9,3,6,5,8,3,2 };
	PrintArray(a5, sizeof(a5) / sizeof(a5[0]));
	/*QuickSort(a5, 0, sizeof(a5) / sizeof(a5[0]) - 1);*/
	QuickSortNoR(a5, 0, sizeof(a5) / sizeof(a5[0]) - 1);
	PrintArray(a5, sizeof(a5) / sizeof(a5[0]));
}


void TestMergesort()
{
	int a6[] = { 4,10,9,3,6,5,8,3,2 };
	Mergesort(a6,sizeof(a6) / sizeof(a6[0]));
	PrintArray(a6, sizeof(a6) / sizeof(a6[0]));
}


void TestMergesortNonR()
{
	int a7[] = { 4,10,9,3,6,5,8,3,2 };
	PrintArray(a7, sizeof(a7) / sizeof(a7[0]));
	MergesortNonR(a7, sizeof(a7) / sizeof(a7[0]));
	PrintArray(a7, sizeof(a7) / sizeof(a7[0]));
}

void TestMergesortNonRNB()
{
	int a7[] = { 4,10,9,3,6,5,8,3,2 };
	PrintArray(a7, sizeof(a7) / sizeof(a7[0]));
	MergesortNonR(a7, sizeof(a7) / sizeof(a7[0]));
	PrintArray(a7, sizeof(a7) / sizeof(a7[0]));
}


void TestCountSort()
{
	int a7[] = { 4,10,9,3,6,5,8,3,2 };
	PrintArray(a7, sizeof(a7) / sizeof(a7[0]));
	CountSort(a7, sizeof(a7) / sizeof(a7[0]));
	PrintArray(a7, sizeof(a7) / sizeof(a7[0]));
}


//比较多种排序的性能

void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();//clock会记录这条程序开始到下一次调用clock程序之间的时间间隔
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	BubbleSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	SelectSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N-1);
	int end5 = clock();

	int begin6 = clock();
	Mergesort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	CountSort(a6, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("BubbleSort:%d\n", end3 - begin3);
	printf("SelcetSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("Mergesort:%d\n", end6 - begin6);
	printf("CountSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}





int main()
{
	TestInsertSort();
	TestSellSort();
	TestBubbleSort();
	TestSelectSort();
	TestQuickSort();
	TestMergesort();
	TestMergesortNonR();
	TestMergesortNonRNB();
	TestCountSort();
	TestOP();
	return 0;
}