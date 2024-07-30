#include"Heap.h"
//���Զ�
//int main()
//{
//	HP hp;
//	HeapInit(&hp);
//	int a[] = { 65,100,70,32,50,60 };
//
//
//	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
//	{
//		HeapPush(&hp, a[i]);
//
//	}
//	while (!HeapEmpty(&hp))
//	{
//		int top = HeapTop(&hp);
//		printf("%d\n", top);
//		HeapPop(&hp);
//	}
//	return 0;
//}



////�ö���������,����ǰ����������Ū����У����ţ����꿽����ȥ
//void HeapSort(int* a, int n)
//{
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(&hp, a[i]);
//
//	}
//	int i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		int top = HeapTop(&hp);
//		a[i++] = top;//����ֵ����������
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//}
//int main()
//{
//	int a[] = { 65,100,70,32,50,60 };
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//
//}








//�ö��������飬�����齨��
//void HeapSort(int* a, int n)
//{
//	//����--�����
//	//����--��С��
//
//	//�����齨��,���ϵ�������
//	//for (int i = 1; i < n; i++)//i=0�ǶѶ�
//	//{
//	//	AdjustUp(a, i);
//	//}
//	//int end = n - 1;
//	//while (end>0)
//	//{
//	//	Swap(&a[0], &a[end]);
//	// ѡ����С��
//	//	AdjustDown(a, end, 0);
//	//	end--;
//	//}
//
//
//	//�����齨�ѣ����µ�������,����
//	for (int i = (n-1-1)/2; i >= 0; i--)//i=0�ǶѶ�
//	{
//		AdjustDown(a, n, i);
//	}
//
//}

//int main()
//{
//	int a[] = { 65,100,70,32,50,60 };
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//
//}






//topk����

void CreatNData()
{
	//������
	//fprintf,fscanf
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (size_t i = 0; i < n; i++)
	{
		int x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	if (KMinHeap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int  i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &KMinHeap[i]);
	}

	//����С�ѣ������ǰk����
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)//i=0�ǶѶ�
	{
		AdjustDown(KMinHeap, k, i);
	}
	int val = 0;
	while (!feof(fout))
	{
		fscanf(fout, "%d", &val);
		if (val > KMinHeap[0])
		{
			KMinHeap[0] = val;
			AdjustDown(KMinHeap, k, 0);
		}
	}


	for (int i = 0; i < k; i++)
	{
		printf("%d\n", KMinHeap[i]);
	}
	printf("\n");
}
int main()
{
	CreatNData();
	PrintTopK(10);
	return 0;
}