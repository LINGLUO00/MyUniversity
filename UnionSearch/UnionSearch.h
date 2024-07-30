#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<vector>
#include<iostream>
class UnionSearch
{
public:
	//creat a UnionSearchSet,a vector with the num of size with tne val -1
	//eg£¬size=3(the people num),the vector is:-1,-1,-1
	UnionSearch(int size)
		:_us(size,-1)
	{}
	//FindRoot
	int FindRoot(int index)
	{

		while (_us[index] >= 0)
		{
			index = _us[index];
		}
		return index;
	}
	//Union,merge two collection
	void Union(int index1, int index2)
	{
		//Find their root
		int root1 = FindRoot(index1);
		int root2 = FindRoot(index2);
		if (root1 != root2)
		{
			//change the num of the collection
			_us[root1] += _us[root2];
			//turn the root2 to the child of root1
			_us[root2] = root1;
		}
	}
	//count the num of the collection
	size_t CountSet()
	{
		int count = 0;
		for (auto e : _us)
		{
			if (e < 0)
			{
				count++;
			}
		}
		return count;
	}
private:
	std::vector<int> _us;
};