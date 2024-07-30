#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"Queue.h"
typedef int BTDataType;


typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
}
BTNode* CreatBinanryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}



void PrevOrder(BTNode* root)//ǰ��
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}



void InOrder(BTNode* root)//����
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	
	InOrder(root->left);
	printf("%d", root->data);
	InOrder(root->right);
}



void PostOrder(BTNode* root)//����
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d", root->data);

}



//�������ڵ����
////����һ�����ü����ķ���
//static int size = 0;//��������������BTreeSize���棬�����������⣺
//					//1�޷��ں�������ʣ��޷���ӡ��2����sizeȥ�����ڶ�������ʱ��size�޷��ÿգ��ں������޷����ʣ�
//void BTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	size++;
//	BTreeSize(root->left);
//	BTreeSize(root->right);
//}

//��������
int BTreeSize(BTNode* root)
{
	//��
	////if (root == NULL)
	//	{
	//		return 0;
	//	}
	//return BTreeSize(root->left) + BTreeSize(root->right) + 1;
	return root == NULL ? 0 : BTreeSize(root->left) + BTreeSize(root->right) + 1;
}


//��Ҷ�ӽڵ����
int BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}


//��������ĸ߶�
int BTreeHeight(BTNode* root)
{
	/*if (root == NULL)
	{
		return 0;
	}
	return BTreeHeight(root->left) > BTreeHeight(root->right) ? BTreeHeight(root->left) + 1 : BTreeHeight(root->right) + 1;*/
//�Ľ�,��Ϊ������ж�Ҫ�ݹ飬��������Ҫ�ݹ�

	if (root == NULL)
	{
		return 0;
	}
	int LeftHeight = BTreeHeight(root->left);//��ѽ��������
	int RightHeight = BTreeHeight(root->right);
	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}

//��������k��ڵ����
int BTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}
	return BTreeLevelKSize(root->left, k - 1) + BTreeLevelKSize(root->right, k - 1);

}


//����������ֵΪx�Ľ��
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}

	BTNode* ret1 = BTreeFind(root->left, x);
	if (ret1)//����ΪNULL�򲻽�ȥ
	{
		return ret1;
	}


	BTNode* ret2 = BTreeFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}


	return NULL;
}


//�������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
}



//���ٶ�����
void BTDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTDestroy(root->left);

	BTDestroy(root->right);

	free(root);
	//������root==NULL��û���õģ���Ϊ�ββ��ı�ʵ�Σ�Ӧ�����õ����Լ��ÿ�
	
}


//�ж��ǲ�����ȫ������
bool BTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//�����վ�����
		if (front == NULL)
			break;
		QueuePush(&q, root->left);
		QueuePush(&q, root->right);
	}
	//������ڵ㻹��û�пգ��оͲ���
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}


	QueueDestroy(&q);
}




int main()
{

	return 0;
}