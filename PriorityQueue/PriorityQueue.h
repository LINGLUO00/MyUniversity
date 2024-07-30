#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
namespace bit
{
	template<class T, class Container = vector<T>, class Compare=Less<T>>
	class priority_queue
	{
	public:
		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if(com(_con[parent] , _con[child]))
				//if (_con[parent] < _con[child])
				{

					swap(_con[child], _con[parent]);
					child = parent;
					parent = (parent - 1) / 2;

				}
				else
				{
					break;
				}
			}
		}
		void adjust_down(int parent)
		{
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() &&  _con[child] < _con[child + 1])
				{
					child++;
				}
				if ( _con[parent] < _con[child])
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;

				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		const T& top()
		{
			return _con[0];
		}
		int size()
		{
			return _con.size();
		}
		bool empty()
		{
			if (_con.size())
			{
				return false;
			}
			return true;
		}
	private:
		Container _con;
	};
}