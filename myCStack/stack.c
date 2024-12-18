#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;//ָ��ջ�����ݵ���һ��λ��
	//pst->top = -1;ָ��ջ������
	pst->capacity = 0;
}

void STPush(ST* pst, STDataType x)
{
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : ((pst->capacity) * 2);
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));//��Ϊtrue
	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));
	return pst->a[pst->top - 1];//ע��
}


void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;

}
