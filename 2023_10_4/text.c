
#include "SList.h"
void TestList1()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);


	SLTPrint(plist);

	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);
	SLTPrint(plist);

	//SLPopBack(&plist);
	//SLPopBack(&plist);

	//SLTPrint(plist);

	//SLPopFront(&plist);
	//SLTPrint(plist);
	 
	 
	
	//���Һ��޸�
	SLTNode* pos = SLTFind(plist,1);
	//pos->data = 30;
	//SLTPrint(plist);

	//������λ�ò���
	SLInsert(&plist,pos, 8);//posǰ
	SLInsertAfter(&plist, pos, 8);//pos��;
	SLTPrint(plist);

	//ɾ��posλ�õ�ֵ



	//ɾ��posλ�ú����ֵ
}

int main()
{
	TestList1();
	return 0;
}