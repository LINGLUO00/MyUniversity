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
	template<class V,class W,W MAX_W=INT_MAX,bool Direction = false>
	class Graph
	{
	public:
		//creat
		Graph() = default;
		Graph(const V* a, size_t n)//an n*n matrix
		{
			_vertexs.reserve(n);
			for (int i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}
			_matrix.resize(n);
			for (size_t i = 0; i < n; i++)
			{
				_matrix[i].resize(n, INT_MAX);
			}
			
		}
		//GetVertexIndex
		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}

		}
		//AddEdge
		void AddEdge(const V& src, const V& dst, const W& w)//cannot be written as a overloaded function,when V is int
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);
			_AddEdge(srci, dsti, w);
		}
		void _AddEdge(const size_t srci, const size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;
			//Undirected graph
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}
		//Print
		void Print()
		{
			//vertex index table
			for (int i = 0; i < _vertexs.size(); i++)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i]<< endl;
			}
			cout << endl;
			//the matrix
			cout << "  ";
			for (int i = 0; i < _matrix.size(); i++)
			{
				printf("%4d", i);
			}
			cout << endl;
			for (int i = 0; i < _matrix.size(); i++)
			{
				cout << i << " ";
				for (int j = 0; j < _matrix[i].size(); j++)
				{
					if (_matrix[i][j] == MAX_W)
					{
						printf("%4c", '*');
					}
					else
					{
						printf("%4d", _matrix[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;
		}

	private:
		vector<V> _vertexs;//save the vertexs
		map<V, int> _indexMap;//store tne subscript corresponding to the vertexs
		vector<vector<W>> _matrix;//creat the matrix
	};


}


namespace link_table
{
	template<class W>
	struct Edge
	{
		size_t _dsti;
		W _w;
		Edge<W>* _next;
		Edge(size_t dsti, const W& w)
			:_dsti(dsti),
			_w(w)
		{
			_next = nullptr;
		}
	};
	template<class V, class W, bool Direction = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph() = default;
		Graph(const V* a, const size_t n)
		{
			_vertexs.reserve(n);
			for (int i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}
			_tables.resize(n, nullptr);
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
				throw invalid_argument("顶点不存在");
				return -1;
			}
		}
		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			Edge* eg = new Edge(dsti, w);
			eg->_next = _tables[srci];//_tables里面都是nullptr，本来就没有人名
			_tables[srci] = eg;
			if (Direction == false)
			{
				Edge* eg = new Edge(srci, w);
				eg->_next = _tables[dsti];
				_tables[dsti] = eg;

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
			for (int i = 0; i < _vertexs.size(); i++)
			{
				cout << "[" << i << "]" << "->" << "[" << _vertexs[i] << "]" << endl;
			}
			cout << endl;
			for (int i = 0; i < _vertexs.size(); i++)
			{
				cout << "[" << _vertexs[i] << "]" << "->";
				Edge* cur = _tables[i];
				while (cur)
				{
					cout << "[" << _vertexs[cur->_dsti] << " " << cur->_w << "]" << "->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}
	private:
		vector<V> _vertexs;
		map<V, int> _indexMap;
		vector<Edge*> _tables;
	};

}