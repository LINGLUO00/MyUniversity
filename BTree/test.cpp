#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
using namespace std;
void TestBtree()
{
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	BTree<int, 3> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.Inorder();
}
int main()
{
	TestBtree();
	return 0;
}