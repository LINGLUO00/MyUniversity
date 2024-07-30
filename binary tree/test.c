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



void PrevOrder(BTNode* root)//前序
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



void InOrder(BTNode* root)//中序
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



void PostOrder(BTNode* root)//后序
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



//二叉树节点个数
////方法一：采用计数的方法
//static int size = 0;//如果把这个定义在BTreeSize里面，会有两个问题：
//					//1无法在函数外访问，无法打印；2当用size去计数第二个树的时候，size无法置空（在函数外无法访问）
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

//方法二：
int BTreeSize(BTNode* root)
{
	//即
	////if (root == NULL)
	//	{
	//		return 0;
	//	}
	//return BTreeSize(root->left) + BTreeSize(root->right) + 1;
	return root == NULL ? 0 : BTreeSize(root->left) + BTreeSize(root->right) + 1;
}


//求叶子节点个数
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


//求二叉树的高度
int BTreeHeight(BTNode* root)
{
	/*if (root == NULL)
	{
		return 0;
	}
	return BTreeHeight(root->left) > BTreeHeight(root->right) ? BTreeHeight(root->left) + 1 : BTreeHeight(root->right) + 1;*/
//改进,因为上面的判断要递归，返回数据要递归

	if (root == NULL)
	{
		return 0;
	}
	int LeftHeight = BTreeHeight(root->left);//会把结果存起来
	int RightHeight = BTreeHeight(root->right);
	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}

//二叉树第k层节点个数
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


//二叉树查找值为x的结点
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
	if (ret1)//返回为NULL则不进去
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


//层序遍历
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



//销毁二叉树
void BTDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTDestroy(root->left);

	BTDestroy(root->right);

	free(root);
	//在这里root==NULL是没有用的，因为形参不改变实参，应该让用的人自己置空
	
}


//判断是不是完全二叉树
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
		//遇到空就跳出
		if (front == NULL)
			break;
		QueuePush(&q, root->left);
		QueuePush(&q, root->right);
	}
	//检查后面节点还有没有空，有就不是
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