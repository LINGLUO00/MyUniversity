
#include "SList.h"
//��ӡ
void SLTPrint(SLTNode* phead)
{

	SLTNode* cur = phead;

	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;

	}
	printf("NULL\n");

}
//ͷ��
void SLPushFront(SLTNode** pphead, Datatype x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->next = *pphead;
	*pphead = newnode;
}

//β�������
SLTNode* AddList(Datatype x)
{
	SLTNode* newnode= (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return 0;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;

}
//β��
void SLPushBack(SLTNode** pphead, Datatype x)
{
	SLTNode* newnode = AddList(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}


//βɾ��ʽһ
//void SLPopBack(SLTNode** plist)
//{
//	SLTNode* pre = NULL;
//	SLTNode* tai = *plist;
//	while (tai->next)
//	{
//		pre = tai;//��pre��tai��ǰһ��λ�ã��Ա��ڽ���λ�õ�next��ΪNULL
//		tai = tai->next;
//	}
//	free(tai);
//	pre->next = NULL;
//}

//βɾ��ʽ��
void SLPopBack(SLTNode** pplist)
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* tai = *pplist;
		while (tai->next->next)
		{
			tai = tai->next;
		}
		tai->next = NULL;
	}
}

//ͷɾ
void SLPopFront(SLTNode** pphead)
{
	assert(*pphead);
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* del = *pphead;
		*pphead = (*pphead)->next;
		free(del);
		del = NULL;

	}
	


}


//����
SLTNode* SLTFind(SLTNode* phead, Datatype x)
{
	SLTNode* cur = phead;
	while (cur->next != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	if (cur->next == NULL && cur->data ==x)
	{
		return cur;
	}

	return NULL;
}

//������λ�ò���posǰ
void SLInsert(SLTNode** pphead,SLTNode* pos, Datatype x)
{
	assert(pphead);
	assert(pos);
	SLTNode* pre = *pphead;
	if ((*pphead) == pos)
	{
		SLPushFront((*pphead), x);
	}
	else
	{

		while (pre->next != pos)
		{
			pre = pre->next;

		}
		SLTNode* newnode = AddList(x);
		pre->next = newnode;
		newnode->next = pos;
	}
}


//������λ�ò���pos��
void SLInsertAfter(SLTNode** pphead, SLTNode* pos, Datatype x)
{
	assert(pphead);
	assert(pos);
	SLTNode* newnode = AddList(x);
	newnode->next = pos->next;
	pos->next = newnode;
}