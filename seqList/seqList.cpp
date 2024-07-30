#include"seqList.h"
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->capacity = 4;
	ps->size = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		cout << *(ps->a + i) << " ";
	}
	cout << endl;
}
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, ps->capacity * 2 * sizeof(SLDateType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;

	}

}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int begin = 0;
	while (begin < ps->size-1)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	assert(ps->size > 0);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			cout << "在第" << i+1 << "位置" << endl;
			return i+1;
		}
		i++;
	}
	
	cout << "没有找到" << endl;
	return -1;
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
		int end = ps->size;
		CheckCapacity(ps);
		while (end >= pos)
		{
			ps->a[end] = ps->a[end-1];
			end--;
		}
		ps->a[pos - 1] = x;
		ps->size++;


}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps && pos <= ps->size);
	int end = ps->size-1;
	while (end>=pos)
	{
		ps->a[end - 1] = ps->a[end];
		end--;
	}
	ps->size--;
}