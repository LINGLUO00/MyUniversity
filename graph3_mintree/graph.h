#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"UnionFindSet.h"
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
				cout << "�����ڶ���" << ":" << v << endl;
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
		struct Edge
		{
			size_t _srci;
			size_t _dsti;
			W _w;
			Edge(size_t srci, size_t dsti, W w)
				:_srci(srci)
				, _dsti(dsti)
				, _w(w)
			{}
			bool operator>(const Edge& e) const//һ��Ҫ����Ϊconst��������벻ͨ��
			{
				return _w > e._w;
			}
		};
		W Kruskal(Self& minTree)
		{
			size_t n = _vertexs.size();
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(n);
			for (int i = 0; i < n; i++)
			{
				minTree._matrix[i].resize(n, MAX_W);
			}
			priority_queue<Edge,vector<Edge>,greater<Edge>> minq;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						minq.push(Edge(i, j, _matrix[i][j]));
					}
				}
			}
			int size = 0;
			W totalW = W();
			UnionFindSet ufs(n);
			while (!minq.empty())
			{
				Edge min = minq.top();
				minq.pop();
				if (!ufs.InSet(min._srci, min._dsti))
				{
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
					minTree._AddEdge(min._srci, min._dsti, _matrix[min._srci][min._dsti]);
					ufs.Union(min._srci, min._dsti);
					size++;
					totalW += min._w;
				}
				else
				{
					cout << "���ɻ���";
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
				}
				
			}
			if (size == n - 1)
			{
				return totalW;
			}
			else
			{
				return W();
			}
		}
		W Prim(Self& minTree,const V& src)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(n);
			for (size_t i = 0; i < n; i++)
			{
				minTree._matrix[i].resize(n);
			}
			vector<bool> X(n, false);
			vector<bool> Y(n, true);
			X[srci] = true;
			Y[srci] = false;
			priority_queue <Edge, vector<Edge>, greater<Edge>> minq;
			for (size_t i = 0; i < n; i++)
			{
				if (_matrix[srci][i] != MAX_W && Y[i])
				{
					minq.push(Edge(srci, i, _matrix[srci][i]));
				}
			}
			size_t size = 0;
			W totalW = W();
			while (!minq.empty())
			{
				Edge min = minq.top();
				minq.pop();
				if (X[min._dsti])
				{
					cout << "���ɻ�:";
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
				}
				else
				{
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
					minTree._AddEdge(min._srci, min._dsti, _matrix[min._srci][min._dsti]);
					X[min._dsti] = true;
					Y[min._dsti] = false;
					size++;
					totalW += min._w;
					if (size == n - 1)
						break;
					for (size_t i = 0; i < n; i++)
					{
						if (_matrix[min._dsti][i] != MAX_W && Y[i])
						{
							minq.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
						}
					}
				}
				
			}
			if (size == n - 1)
			{
				return totalW;
			}
			else
			{
				return W();
			}

		}
		private:
			vector<V> _vertexs;			// ���㼯��
			map<V, int> _indexMap;		// ����ӳ���±�
			vector<vector<W>> _matrix;  // �ڽӾ���
	};
}

