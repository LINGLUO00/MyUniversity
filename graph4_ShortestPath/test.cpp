#define _CRT_SECURE_NO_WARNINGS 1
#include"ShortestPath.h"
void TestGraphDijkstra()
{
	const char* str = "syztx";
	matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.AddEdge('s', 't', 10);
	g.AddEdge('s', 'y', 5);
	g.AddEdge('y', 't', 3);
	g.AddEdge('y', 'x', 9);
	g.AddEdge('y', 'z', 2);
	g.AddEdge('z', 's', 7);
	g.AddEdge('z', 'x', 6);
	g.AddEdge('t', 'y', 2);
	g.AddEdge('t', 'x', 1);
	g.AddEdge('x', 'z', 4);

	vector<int> dist;
	vector<int> parentPath;
	g.Dijkstra('s', dist, parentPath);
	g.PrintShortPath('s', dist, parentPath);
}
void TestGraphBellmanFord()
{
	/*	const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', 8);
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		g.BellmanFord('s', dist, parentPath);
		g.PrintShortPath('s', dist, parentPath);*/

	const char* str = "syztx";
	matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.AddEdge('s', 't', 6);
	g.AddEdge('s', 'y', 7);
	g.AddEdge('y', 'z', 9);
	g.AddEdge('y', 'x', -3);
	//g.AddEdge('y', 's', 1); // 新增
	g.AddEdge('z', 's', 2);
	g.AddEdge('z', 'x', 7);
	g.AddEdge('t', 'x', 5);
	//g.AddEdge('t', 'y', -8); //更改
	g.AddEdge('t', 'y', 8);

	g.AddEdge('t', 'z', -4);
	g.AddEdge('x', 't', -2);
	vector<int> dist;
	vector<int> parentPath;
	if (g.BellmanFord('s', dist, parentPath))
		g.PrintShortPath('s', dist, parentPath);
	else
		cout << "带负权回路" << endl;
}


void TestFloydWarShall()
{
	const char* str = "12345";
	matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.AddEdge('1', '2', 3);
	g.AddEdge('1', '3', 8);
	g.AddEdge('1', '5', -4);
	g.AddEdge('2', '4', 1);
	g.AddEdge('2', '5', 7);
	g.AddEdge('3', '2', 4);
	g.AddEdge('4', '1', 2);
	g.AddEdge('4', '3', -5);
	g.AddEdge('5', '4', 6);
	vector<vector<int>> vvDist;
	vector<vector<int>> vvParentPath;
	g.FloydWarshall(vvDist, vvParentPath);

	// 打印任意两点之间的最短路径
	for (size_t i = 0; i < strlen(str); ++i)
	{
		g.PrintShortPath(str[i], vvDist[i], vvParentPath[i]);
		cout << endl;
	}
}
int main()
{
	//TestGraphDijkstra();
	//TestGraphBellmanFord();
	TestFloydWarShall();
	return 0;
}