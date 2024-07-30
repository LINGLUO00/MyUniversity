#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <functional>
#include<iostream>
using namespace std;
// weight
namespace matrix
{
	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> Self;
	public:
		Graph() = default;

		// 图的创建
		// 1、IO输入  -- 不方便测试,oj中更适合
		// 2、图结构关系写到文件，读取文件
		// 3、手动添加边
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_matrix.resize(n);
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				_matrix[i].resize(n, MAX_W);
			}
		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			else
			{
				//assert(false);
				cout << "不存在顶点" << ":" << v << endl;
				throw invalid_argument("顶点不存在");

				return -1;
			}
		}


		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;
			// 无向图
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);
			_AddEdge(srci, dsti, w);
		}

		void Print()
		{
			// 顶点
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			// 矩阵
			// 横下标
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				//cout << i << " ";
				printf("%4d", i);
			}
			cout << endl;

			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " "; // 竖下标
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					//cout << _matrix[i][j] << " ";
					if (_matrix[i][j] == MAX_W)
					{
						//cout << "* ";
						printf("%4c", '*');
					}
					else
					{
						//cout << _matrix[i][j] << " ";
						printf("%4d", _matrix[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;

			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						cout << _vertexs[i] << "->" << _vertexs[j] << ":" << _matrix[i][j] << endl;
					}
				}
			}

		}
		void PrintShortPath(const V& src, const vector<W>& dist, const vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			for (size_t i = 0; i < n; i++)
			{
				if (i != srci)
				{
					size_t parenti = i;
					vector<int> path;
					while (parenti != srci)
					{
						path.push_back(parenti);
						parenti = pPath[parenti];
					}
					path.push_back(srci);
					reverse(path.begin(), path.end());
					for (auto e : path)
					{
						cout << _vertexs[e] << "->";
					}
					cout << dist[i] << endl;
				}
			}
		}
		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = 0;
			pPath[srci] = srci;
			vector<bool> S(n, false);
			for (size_t i = 0; i < n; i++)
			{
				int u = 0;
				W min = MAX_W;
				for (size_t j = 0; j < n; j++)
				{
					if (S[j] == false && dist[j] < min)
					{
						u = i;
						min = dist[j];
					}
				}
				S[u] = true;
				for (size_t v = 0; v < n; v++)
				{
					if (S[v] == false && _matrix[u][v] != MAX_W && dist[u] + _matrix[u][v] < dist[v])
					{
						dist[v] = dist[u] + _matrix[u][v];
						pPath[v] = u;
					}
				}
			}

		}



	private:
		vector<V> _vertexs;			// 顶点集合
		map<V, int> _indexMap;		// 顶点映射下标
		vector<vector<W>> _matrix;  // 邻接矩阵
	};
}