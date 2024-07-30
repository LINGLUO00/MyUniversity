#define _CRT_SECURE_NO_WARNINGS 1
#include"seqList.h"
void TestSeqList()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);

	int pos = SeqListFind(&s, 6);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	SeqListPrint(&s);

	SeqListDestroy(&s);
}
int main()
{
	TestSeqList();
	return 0;
}