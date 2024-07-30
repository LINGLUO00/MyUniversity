#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

#include "Stack.h"


void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
void InsertSort(int* a, int n)
{
	//ʱ�临�Ӷȣ����O(N),�O(N^2)
	for (int i = 1; i < n; i++)
	{
		int end = i-1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])//�Ĳ��Ⱥż�����
			{
				a[end + 1] = a[end];
				end--;

			}
			else
				break;

		}
		a[end + 1] = tmp;
	}
}


////ϣ�������Ԥ����
//void ShellSort(int* a, int n)
//{
//	//���Ϊgap��Ϊһ�飬�ܼ�gap��
//	int gap = 3;
//	for (int j=0;j<gap;j++)
//	{
//		
//		for (int i = j; i < n - gap; i = i + gap)//�����i<n�Ļ���tmp����Խ�磬��end�����һ����
//		{//������i=j��������end++�������ƣ����end�������for���������
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//					break;
//
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}




//ϣ�������Ԥ���򣨶��鲢�Ű汾
void ParallelShellSort(int* a, int n)
{
	//���Ϊgap��Ϊһ�飬�ܼ�gap��
	int gap = 3;
	for (int i = 0; i < n - gap; i++)//����ֻ��дһ��ѭ�������������ѭ���ģ�ֻ����i=0��i++
	{//��gapΪ1��ʱ�򣬾��ǲ�������
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			else
				break;

		}
			a[end + gap] = tmp;
	}
}




//ϣ�����򣨶��鲢�Ű汾
//ʱ�临�Ӷ�O(N^(3/2))
void ShellSort(int* a, int n)
{
	//���Ϊgap��Ϊһ�飬�ܼ�gap��
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//���һ��gapΪ1��Ҳ����дgap=gap/2,Ԥ�Ÿ���

		for (int i = 0; i < n - gap; i++)
		{//��gapΪ1��ʱ�򣬾��ǲ�������
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;

			}
			a[end + gap] = tmp;
		}
	}
}





//ð������
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		bool exchange = false;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				int tmp = a[i-1];
				a[i - 1] = a[i];
				a[i] = tmp;
				exchange = true;
			}
		}
		if (exchange == false)//���exchange��Ϊfalse��˵����������������ģ���ֹð��
		{
			break;
		}
	}
}



//ѡ������
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}


		Swap(&a[begin], &a[mini]);
		//���maxi��begin�ص�������һ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}




//���ŵ�3�����Ű汾

int GetMidIndex(int* a, int left, int right)//����ȡ����key
{
	//�ò��̶�������ȡ��,���ҹ̶���֮���������ֹ���������ж��Ƚ�С���߱Ƚϴ�
	int mid = left + (rand() % (right - left));
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
			return left;
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return right;
		}
		else
			return left;
	}

}



//hoare�汾
int  PartSort(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	//�����key���ұ����ߣ�����������λ�õ�ֵ��keyС
	int keyi = left;
	while (left < right)
	{
		//�ұ���С
		while (left < right && a[right] >= a[keyi])//��ֹrightһֱ����
		{
			right--;
		}
		//�����С
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}



//�ڿӷ�
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//�ұ���С
		while (left < right && a[right] >= key)//��ֹrightһֱ����
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		//�����С
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}


//˫ָ�뷨
int PartSort2(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	//cur����С�����a[cur]<key,prev++������prev��curλ��
	int prev = left;
	int cur = left + 1;
	int keyi = left;

	while (cur<=right)
	{
		if ( a[cur] <= a[keyi] && prev++ != cur)//�����ִ��prev�Ӽӣ�����prev != curΪ�٣����ɻ�ִ��prev++�����Բ��ܰѺ�������ж�д��ǰ��
		{
			Swap(&a[prev], &a[cur]);
		}
		//�����if�ֿ���д����
		//if (a[cur] <= a[keyi] && prev != cur)
		//{
		//	prev++;
		//	Swap(&a[prev], &a[cur]);
		//}
		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}


//���ŵݹ�
//ʱ�临�Ӷȣ�O(logN*N)
//�ռ临�Ӷȣ�O(logN)
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = PartSort2(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi+1, end);
}


//���ŷǵݹ�
void QuickSortNoR(int* a, int begin, int end)
{
	ST st;
	STInit(&st);
	STPush(&st, end);
	STPush(&st, begin);
	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);


		int right = STTop(&st);
		STPop(&st);



		int keyi = PartSort2(a, left, right);
		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi + 1);
		}


		if (left < keyi-1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, left);
		}
	}




	STDestroy(&st);
}













//�鲢����ݹ�汾
//ʱ�临�Ӷȣ�O��N* logN��
//�ռ临�Ӷȣ�O(N)
void _Mergesort(int* a, int begin, int end, int* tmp)
{
	if (begin == end)
		return;

	//�Ż�
	if (end - begin + 1 < 10)
	{
		InsertSort(a, end - begin + 1);
		return;
	}




	int mid = (begin + end) / 2;
	_Mergesort(a, begin, mid, tmp);
	_Mergesort(a, mid+1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}


	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a+begin, tmp+begin, sizeof(int) * (end - begin + 1));



}
void Mergesort(int* a, int n)
{
	int* tmp = (int*) malloc(sizeof(int) * n);


	_Mergesort(a, 0, n - 1, tmp);


	free(tmp);
}



//�鲢����ǵݹ�汾


void MergesortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{

			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (end1 >= n || begin2 >= n)
			{
				break;
			}




			//����
			if (end2 >= n)
			{
				end2 = n - 1;
			}




			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}


			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a+i, tmp+i, sizeof(int) * (end2-i+1));
		}
		gap *= 2;
	}
	free(tmp);

}



//NO break�汾
void MergesortNonRNB(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{

			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;


			printf("����ǰ��[%d %d][%d %d]\n", begin1, end1, begin2, end2);
			if (end1 >= n)
			{
				end1 = n - 1;
				//Խ����޳ɲ����ڵ�����,����ȥ�����һ��while
				begin2 = n;
				end2 = n - 1;
			}


			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			printf("������[%d %d][%d %d]\n", begin1, end1, begin2, end2);




			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}


			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);

}







//��Դ����ظ����ݵĿ����Ż�
//��·����
//С���󣬴����ң���key��ȸ��м�
void QuickSortT(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int left = begin;
	int right = end;
	int cur = left + 1;


	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);




	int key = a[left];

	while (cur <= right)
	{
		if (a[cur] < key)
		{
			Swap(&a[left], &a[cur]);
			left++;
			cur++;
		}
		else if (a[cur] > key)
		{
			Swap(&a[cur], &a[right]);
			right--;
		}
		else
		{
			cur++;
		}
	}


	int keyi = PartSort2(a, begin, end);
	QuickSortT(a, begin, left - 1);
	QuickSortT(a, right+1 , end);
}






//��������
//ͳ�Ƴ�ÿ�����ݳ��ֵĴ���
//����ͳ�ƴ�������
//ʱ�临�Ӷȣ�O(N+Range)
//�ռ临�Ӷȣ�O(Range)
//ȱ�ݣ�ֻ�������κ����ݼ��е�����
void CountSort(int* a,int n)
{
	
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;
	int* CountA = (int*)malloc(sizeof(int) * range);
	memset(CountA, 0, sizeof(int) * range);





	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		CountA[a[i] - min]++;
	}

	//��������
	int k = 0;
	for (int j = 0; j < range; j++)
	{
		while (CountA[j]--)
		{
			a[k++] = j + min;
		}
	}
}