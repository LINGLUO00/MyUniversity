#include"PriorityQueue.h"
using namespace std;
template <class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}

};
void test_priority_queue()
{
	bit::priority_queue<int> q;
	q.push(3);
	q.push(2);
	q.push(4);
	q.push(6);
	q.push(7);
	bit::priority_queue<int> copy(q);
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();

	}
	cout << endl;
}


//int main()
//{
//	test_priority_queue();
//	Less less;
//	cout << less(2, 3) << endl;
//	return 0;
//}






//非类型模板参数
template<class T, size_t N>
class Stack
{
private:
	T _a[N];
};
int main()
{
	Stack<int, 10>st1;
	Stack <double, 100>st2;
	return 0;
}

