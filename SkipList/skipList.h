#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <chrono>
using namespace std;
struct SkiplistNode
{
	int _val;
	vector<SkiplistNode*> _nextV;
	SkiplistNode(int val, int level)
		:_val(val)
		, _nextV(level, nullptr)
	{}

};
class Skiplist
{
	typedef SkiplistNode Node;
public:
	Skiplist()
	{
		srand(time(0));
		_head = new Node(-1, 1);
	}
	bool search(int target)
	{
		Node* cur = _head;
		int level = _head->_nextV.size() - 1;
		while (level >= 0)
		{
			if (cur->_nextV[level] && target > cur->_nextV[level]->_val)
			{
				cur = cur->_nextV[level];
			}
			else if (cur->_nextV[level] == nullptr || target < cur->_nextV[level]->_val)
			{
				level--;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	vector<Node*> FindPrevNode(int num)
	{
		Node* cur = _head;
		int level = _head->_nextV.size() - 1;
		vector<Node*> prevV(level + 1, _head);
		while (level >= 0)
		{
			if (cur->_nextV[level] && num > cur->_nextV[level]->_val)
			{
				cur = cur->_nextV[level];
			}
			else if (cur->_nextV[level] == nullptr || num <= cur->_nextV[level]->_val)
			{
				prevV[level] = cur;
				level--;
			}
		}
		return prevV;
	}

	void add(int num)
	{
		vector<Node*> prevV = FindPrevNode(num);
		int n = RandomLevel();
		Node* newNode = new Node(num, n);
		if (n > _head->_nextV.size())
		{
			_head->_nextV.resize(n, nullptr);
			prevV.resize(n, _head);
		}
		for (int i = 0; i < n; i++)
		{
			newNode->_nextV[i] = prevV[i]->_nextV[i];
			prevV[i]->_nextV[i] = newNode;
		}
	}
	bool erase(int num)
	{
		vector<Node*> prevV = FindPrevNode(num);
		if (prevV[0]->_nextV[0] == nullptr || prevV[0]->_nextV[0]->_val != num)
		{
			return false;
		}

		else
		{
			Node* del = prevV[0]->_nextV[0];
			for (int i = 0; i < del->_nextV.size(); i++)
			{
				prevV[i]->_nextV[i] = del->_nextV[i];
			}
			delete del;

			int i = _head->_nextV.size() - 1;
			while (i >= 0)
			{
				if (_head->_nextV[i] == nullptr)
					i--;
				else
					break;
			}
			_head->_nextV.resize(i + 1);
			return true;

		}
	}
	//C++random
	/*int RandomLevel()
	{
		static std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
		static std::uniform_real_distribution<double> distribution(0.0, 1.0);
		int level = 1;
		while (distribution(generator) < p && level < _maxLevel)
		{
			level++;
		}
		return level;
	}*/


	//C random
	int RandomLevel()
	{
		int level = 1;
		while (rand() < RAND_MAX * p && level < _maxLevel)
		{
			level++;
		}
		return level;
	}
	void Print()
	{
		Node* cur = _head;
		while (cur)
		{
			printf("%2d\n", cur->_val);
			// ?????????cur???
			for (auto e : cur->_nextV)
			{
				printf("%2s", "¡ý");
			}
			printf("\n");

			cur = cur->_nextV[0];
		}
	}
private:
	Node* _head;
	int _maxLevel = 32;
	double p = 0.5;
};