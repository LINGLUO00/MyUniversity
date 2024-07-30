#include"Func.h"

class Stack
{
public:
	//Stack()
	//{
	//	_a = nullptr;
	//	_top = 0;
	//	_capacity = 0;

	//}
	////为了避免多次扩容，让空间可以由用户说明
	//Stack(int n = 4)
	//{
	//	if (n == 0)
	//	{
	//		_a = nullptr;
	//		_top = _capacity = 0;
	//		_size = 0;
	//	}
	//	else
	//	{
	//		_a = (int*)realloc(_a, sizeof(int) * n);
	//		if (_a == nullptr)
	//		{
	//			perror("realloc fail");
	//			exit(-1);
	//		}
	//		_top = 0;
	//		_capacity = 0;
	//		_size = 0;
	//	}
	//}
	Stack(int n = 4)
	{
		if (n == 0)
		{
			_a = nullptr;
			_top = _capacity = 0;
			_size = 0;
		}
		else
		{
			_a = new int[n];
			_top = 0;
			_capacity = 0;
			_size = 0;
		}
	}
	~Stack()//就不用写destroy了
	{
		delete[] _a;
		_a = nullptr;
		_capacity = 0;
		_size = 0;
	}
	Stack(const Stack& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			return;
		}
		memcpy(_a, st._a, sizeof(int) * st._size);
		_size = st._size;
		_capacity = st._capacity;
		_top = st._top;
	}
	void Push(int x)
	{
		if (_top == _capacity)
		{
			int NewCapacity = _capacity == 0 ? 4 : _capacity * 2;
			int* tmp = (int*)realloc(_a, sizeof(int) * NewCapacity);
			if (tmp == nullptr)
			{
				perror("realloc fail");
				exit(-1);
			}
			_a = tmp;
			_capacity = NewCapacity;
			_size++;
			_a[_top++] = x;
			
		}
		else
		{
			_a[_top++] = x;
			_size++;
		}
	}
	int Top()
	{
		return _a[_top-1];
	}
	void Pop()
	{
		assert(_top > 0);
		_top--;
		_size--;
	}
	void Destroy()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;

	}
	bool Empty()
	{
		return _top == 0;
	}
private:
	int* _a;
	int _top;
	int _capacity;
	int _size;
};


class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date(int year = 2024, int month = 2, int day = 18)
	{
		if (month < 1 || month>12 || day<1 || day>GetMonthDay(year, month))
		{
			cout << "日期非法" << endl;
			exit(-1);
		}
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;//支持连续赋值
	}
	bool operator==(const Date& d2)
	{
		return _year == d2._year && _month == d2._month && _day == d2._day;
	}
	bool operator<=(const Date& d2)
	{
		return *this < d2 || *this == d2;
	}
	bool operator>(const Date& d2)
	{
		return !(*this <= d2);
	}
	bool operator >=(const Date& d2)
	{
		return !(*this < d2);
	}
	bool operator !=(const Date& d2)
	{
		return !(*this == d2);
	}
	int GetMonthDay(int year, int month)
	{
		static int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//加上static不用每一次都创建
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) )
		{
			return 29;
		}
		return monthArray[month];
	}
	Date& operator+=(int day)//日期加天数的返回值仍为日期
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month); 
			_month++;
			if (_month > 12)
			{
				_month %= 12;
				_year++;
			}
		}
		return *this;
	}
	Date operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
	}

	Date& operator++()
	{
		return *this += 1;
	}
	//void operator<<()//这样写顺序有问题，写成全局的，就可以解决*this，因为全局的没有这个隐含参数
	//{
	//	out << _year << "/" << _month << "/" << _day << "/" << endl;
	//}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << "/" << endl;
	return out;
}

Stack* func()
{
	int n;
	cin >> n;
	Stack* pst = new Stack(n);
	return pst;
}




int main()
{
	//Stack st;
	//st.Push(1);
	//st.Push(5);
	//st.Push(8);
	//Stack st1(st);
	//while (!st.Empty())
	//{
	//	cout << st.Top() << " ";
	//	st.Pop();

	//}
	//cout << endl;
	//while (!st1.Empty())
	//{
	//	cout << st1.Top() << " ";
	//	st1.Pop();

	//}
	//cout << endl;
	Date d1(2024, 2, 1);
	Date d2(2024, 3, 5);

	if (d1 <= d2)
	{
		cout << "d1<=d2" << endl;
	}

	Date ret = d1 + 50;
	cout << ret << d1;//从左往右顺序执行的，不是赋值那种，赋值那种才是特殊的





	return 0;
}