#define _CRT_SECURE_NO_WARNINGS 1
#include"graph.h"
void TestBDFS()
{
	string a[] = { "����", "����", "����", "����", "����" };
	matrix::Graph<string, int> g1(a, sizeof(a) / sizeof(string));
	g1.AddEdge("����", "����", 100);
	g1.AddEdge("����", "����", 200);
	g1.AddEdge("����", "����", 30);
	g1.AddEdge("����", "����", 30);
	g1.Print();

	g1.BFS("����");
	cout << "����" << endl;
	g1.DFS("����");
}
int main()
{
	TestBDFS();
	return 0;
}