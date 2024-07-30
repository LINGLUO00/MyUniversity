#define _CRT_SECURE_NO_WARNINGS 1
#include"graph.h"
#include"UnionFindSet.h"
void TestGraphMinTree()
{
	const char str[] = "abcdefghi";
	matrix::Graph<char, int> g(str, strlen(str));
	g.AddEdge('a', 'b', 4);
	g.AddEdge('a', 'h', 8);
	//g.AddEdge('a', 'h', 9);
	g.AddEdge('b', 'c', 8);
	g.AddEdge('b', 'h', 11);
	g.AddEdge('c', 'i', 2);
	g.AddEdge('c', 'f', 4);
	g.AddEdge('c', 'd', 7);
	g.AddEdge('d', 'f', 14);
	g.AddEdge('d', 'e', 9);
	g.AddEdge('e', 'f', 10);
	g.AddEdge('f', 'g', 2);
	g.AddEdge('g', 'h', 1);
	g.AddEdge('g', 'i', 6);
	g.AddEdge('h', 'i', 7);

	matrix::Graph<char, int> kminTree;
	cout << "Kruskal:" << g.Kruskal(kminTree) << endl;
	kminTree.Print();
	cout << endl << endl;

	matrix::Graph<char, int> pminTree;
	cout << "Prim:" << g.Prim(pminTree, 'a') << endl;
	pminTree.Print();
	cout << endl;

	for (size_t i = 0; i < strlen(str); ++i)
	{
		cout << "Prim:" << g.Prim(pminTree, str[i]) << endl;
	}
}
int main()
{
	TestGraphMinTree();
	return 0;
}