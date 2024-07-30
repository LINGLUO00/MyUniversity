#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include<iostream>
using namespace std;
namespace matrix
{
	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> Self;
	public:
		Graph() = default;

		// ͼ�Ĵ���
		// 1��IO����  -- ���������,oj�и��ʺ�
		// 2��ͼ�ṹ��ϵд���ļ�����ȡ�ļ�
		// 3���ֶ���ӱ�
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
				throw invalid_argument("���㲻����");

				return -1;
			}
		}


		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;
			// ����ͼ
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
			// ����
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			// ����
			// ���±�
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				//cout << i << " ";
				printf("%4d", i);
			}
			cout << endl;

			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " "; // ���±�
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
		}
		void BFS(const V& src)
		{
			size_t srci = GetVertexIndex(src);
			queue<int> q;
			vector<bool> visited(_vertexs.size(), false);
			q.push(srci);
			visited[srci] = true;
			size_t levelSize = 1;
			while (!q.empty())
			{
				for (size_t i = 0; i < levelSize; i++)
				{
					size_t front = q.front();
					q.pop();
					cout << front << ":" << _vertexs[front] << endl;
					for (size_t i = 0; i < _vertexs.size(); i++)
					{
						if (visited[i] == false && _matrix[front][i] != MAX_W)
						{
							q.push(i);
							visited[i] = true;
						}
					}
				}
				cout << endl;
				levelSize = q.size();

			}

		}
		void _DFS(const int& srci, vector<bool>& visited)
		{
			cout << srci << ":" << _vertexs[srci] << endl;
			visited[srci] = true;
			for (int i = 0; i < _vertexs.size(); i++)
			{
				if (visited[i] != true && _matrix[srci][i] != MAX_W)
				{
					_DFS(i, visited);
				}
			}
		}
		void DFS(const V& src)
		{
			int srci = GetVertexIndex(src);
			vector<bool> visited(_vertexs.size(), false);
			_DFS(srci, visited);
		}
		private:
			vector<V> _vertexs;			// ���㼯��
			map<V, int> _indexMap;		// ����ӳ���±�
			vector<vector<W>> _matrix;  // �ڽӾ���
	};
}