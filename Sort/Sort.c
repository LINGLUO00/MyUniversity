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

//插入排序
void InsertSort(int* a, int n)
{
	//时间复杂度：最好O(N),最坏O(N^2)
	for (int i = 1; i < n; i++)
	{
		int end = i-1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])//改不等号即降序
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


////希尔排序的预排序
//void ShellSort(int* a, int n)
//{
//	//间隔为gap分为一组，总计gap组
//	int gap = 3;
//	for (int j=0;j<gap;j++)
//	{
//		
//		for (int i = j; i < n - gap; i = i + gap)//如果用i<n的话，tmp最后会越界，当end在最后一个数
//		{//这里用i=j，而不用end++，来控制，解决end定义这个for里面的问题
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




//希尔排序的预排序（多组并排版本
void ParallelShellSort(int* a, int n)
{
	//间隔为gap分为一组，总计gap组
	int gap = 3;
	for (int i = 0; i < n - gap; i++)//这种只用写一个循坏，相比于两个循坏的，只改了i=0和i++
	{//当gap为1的时候，就是插入排序
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




//希尔排序（多组并排版本
//时间复杂度O(N^(3/2))
void ShellSort(int* a, int n)
{
	//间隔为gap分为一组，总计gap组
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//最后一次gap为1，也可以写gap=gap/2,预排更多

		for (int i = 0; i < n - gap; i++)
		{//当gap为1的时候，就是插入排序
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





//冒泡排序
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
		if (exchange == false)//如果exchange仍为false，说明，本来就是有序的，终止冒泡
		{
			break;
		}
	}
}



//选择排序
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
		//如果maxi和begin重叠，修正一下
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}




//快排的3个单排版本

int GetMidIndex(int* a, int left, int right)//三数取中找key
{
	//用不固定的三数取中,左右固定，之间随机，防止出现左右中都比较小或者比较大
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



//hoare版本
int  PartSort(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	//左边做key，右边先走，保障了相遇位置的值比key小
	int keyi = left;
	while (left < right)
	{
		//右边找小
		while (left < right && a[right] >= a[keyi])//防止right一直减减
		{
			right--;
		}
		//左边找小
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}



//挖坑法
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//右边找小
		while (left < right && a[right] >= key)//防止right一直减减
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		//左边找小
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


//双指针法
int PartSort2(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	//cur在找小，如果a[cur]<key,prev++，交换prev和cur位置
	int prev = left;
	int cur = left + 1;
	int keyi = left;

	while (cur<=right)
	{
		if ( a[cur] <= a[keyi] && prev++ != cur)//这里会执行prev加加，就算prev != cur为假，依旧会执行prev++，所以不能把后面这个判断写在前面
		{
			Swap(&a[prev], &a[cur]);
		}
		//上面的if分开来写就是
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


//快排递归
//时间复杂度：O(logN*N)
//空间复杂度：O(logN)
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


//快排非递归
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













//归并排序递归版本
//时间复杂度：O（N* logN）
//空间复杂度：O(N)
void _Mergesort(int* a, int begin, int end, int* tmp)
{
	if (begin == end)
		return;

	//优化
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



//归并排序非递归版本


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




			//修正
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



//NO break版本
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


			printf("修正前：[%d %d][%d %d]\n", begin1, end1, begin2, end2);
			if (end1 >= n)
			{
				end1 = n - 1;
				//越界的修成不存在的区间,进不去下面第一个while
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

			printf("修正后：[%d %d][%d %d]\n", begin1, end1, begin2, end2);




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







//针对大量重复数据的快排优化
//三路划分
//小在左，大在右，跟key相等搞中间
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






//计数排序
//统计出每个数据出现的次数
//根据统计次数排序
//时间复杂度：O(N+Range)
//空间复杂度：O(Range)
//缺陷：只用于整形和数据集中的数组
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





	//统计次数
	for (int i = 0; i < n; i++)
	{
		CountA[a[i] - min]++;
	}

	//排序数组
	int k = 0;
	for (int j = 0; j < range; j++)
	{
		while (CountA[j]--)
		{
			a[k++] = j + min;
		}
	}
}