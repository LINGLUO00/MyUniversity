#include"Heap.h"
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;

}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}


void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//假设法选出左右孩子中小的
		if (child+1 <n && a[child + 1] < a[child])//这个条件不能反，因为，【】会检查越界
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}


	}
}



void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			//HPDataType tmp = a[parent];
			//a[parent] = a[child];
			//a[child] = tmp;

			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;

		}

		else
		{
			break;
		}
	}



}
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;

	}
	php->a[php->size] = x;
	php->size++;
	//向上调整
	AdjustUp(php->a, php->size - 1);
}


//默认删除栈顶元素
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}



bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

int HeapSize(HP*php)
{
	assert(php);
	return php->size;
}



