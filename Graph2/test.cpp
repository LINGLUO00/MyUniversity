#define _CRT_SECURE_NO_WARNINGS 1
#include"graph.h"
void TestBDFS()
{
	string a[] = { "张三", "李四", "王五", "赵六", "周七" };
	matrix::Graph<string, int> g1(a, sizeof(a) / sizeof(string));
	g1.AddEdge("张三", "李四", 100);
	g1.AddEdge("张三", "王五", 200);
	g1.AddEdge("王五", "赵六", 30);
	g1.AddEdge("王五", "周七", 30);
	g1.Print();

	g1.BFS("张三");
	cout << "隔开" << endl;
	g1.DFS("张三");
}
int main()
{
	TestBDFS();
	return 0;
}