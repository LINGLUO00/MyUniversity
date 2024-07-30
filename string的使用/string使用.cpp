#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
////1.模板：
// //1.1
//template<class T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 4;
//	int b = 9;
//	swap(a, b);
//	cout << a << b << endl;
//	
//
//	double c = 5.4;
//	double d = 3.4;
//	swap(c, d);
//	cout << c << d << endl;
//	cout<< Add(a, b)<<' '<< Add(c, d) << endl;
//	return 0;
//}




//1.2
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		:_pData(new T[capacity])
//		,_size(0)
//		,_capacity(capacity)
//	{}
//	// 使用析构函数演示：在类中声明，在类外定义。
//	//不建议声明和定义分离，如果分到两个文件就会报错
//	~Vector();
//
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//template<class T>
//Vector<T>::~Vector()
//{
//	delete[] _pData;
//	_pData = nullptr;
//}
//
//
//// 类名 ： Vector
//// 类型 ： Vector<T>
// 不能说模具是铁
//
//int main()
//{
//    Vector<int> v;
//    return 0;
//}



//2.string的使用
//void test_string1()
//{
//	string s1;
//	string s2("hello");
//	cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	string ret1 = s1 + s2;
//	cout << ret1 << endl;
//	string ret2 = s2 + " world";
//	cout << ret2 << endl;
//
//}

void test_string2()
{
	string s1("hello world");
	string s2 = "hello world";
	////遍历string(for循环下标访问）
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	//读
	//	cout << s1[i] << " ";
	//}
	//cout << endl;
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	//写
	//	s1[i]++;
	//}
	//cout << s1 << endl;
	




	////遍历string(迭代器）
	//string::iterator it = s1.begin();
	//while (it != s1.end())
	//{
	//	//读
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	//it = s1.begin();
	//while (it != s1.end())
	//{
		// 写
	//	*it = 'a';
	//	++it;
	//}
	//cout << endl;
	//cout << s1 << endl;


	//////遍历（范围for）
	//for (auto ch : s1)
	//{
	//	//读
	//	cout << ch << " ";
	//}
	//cout << endl;
	//for (auto& ch : s1)//必须是返回s1的引用，因为范围for是从s1,拷贝到ch，ch的改变不影响s1，加引用让ch成为s1的别名
	//{
	//	//写
	//	cout << ++ch;
	//}
	//cout << endl;
	//cout << s1 << endl;

	//倒着遍历(这里的auto为string::reverse_iterator 
	//auto rit = s1.rbegin();
	//while (rit != s1.rend())
	//{
	//	cout << *rit;
	//	rit++;
	//}
	//cout << endl;



}


////对于const变量要调用const类型的迭代器，因为普通迭代器是可以写的,权限被放大了
//void func(const string& s)
//{
//	auto it = s.begin();//string::const_iterator it =s.begin();
//	while (it != s.end())
//	{
//		//不支持写
//
//		/**it = 'a';*/
//		//只能读
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//
//
//
//int main()
//{
//	test_string2();
//	string s("hello world");
//	func(s);
//	return 0;
//}


////3.string的各种传参
//void test_string3()
//{
//	string s1("hello world");
//	string s2(s1);
//	cout << s2 << endl;
//	string s3(s1, 5, 4);//删去前5个，往后保留4个
//	cout << s3 << endl;
//	string s4(s1, 5);//删去前5个，然后打印到底
//	cout << s4 << endl;
//	string s5(10,'a');//设置一个字符串并将10个值初始化为a
//	cout << s5 << endl;
//	string s6(s1, 6, s1.size() - 6);//同s3
//	cout << s6 << endl;
//	string s8(++s1.begin(), --s1.end());//打印区间
//	cout << s8 << endl;
//}
//int main()
//{
//	test_string3();
//	return 0;
//}


//4.1string的各种内置函数
void test_string5()
{
	//string s1("hello world");
	//cout << s1.size() << endl;//其实string一开始只有length，这是C语言延续下来的习惯
	////而size则是在出现STL之后，为了兼容加入了和STL容器求长度的函数一个名字的size，这样就可以方便的使用于STL的算法
	//cout << s1.length() << endl;
	//cout << s1.capacity() << endl;//多开是为了\0
	//s1.clear();//不清空capacity,size是用来计算字符串大小的，别和capacity混了
	//s1 += "hehe";
	//cout << s1 << endl;
	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;


	//string filename;
	//cin >> filename;
	//FILE* fout = fopen(filename.c_str(), "r");//不能只写filename,因为c的接口不认识,使用c_str来兼容c

	//string s2;
	//s2.reserve(10);//提前开空间,capacity实际为16，因为他打印给用户的是能存多少有效字符
	//size_t old = s2.capacity();
	//cout << "初始" << s2.capacity() << endl;
	//for (int i = 0; i < 100; i++)
	//{
	//	s2.push_back('x');
	//	if (s2.capacity() != old)
	//	{
	//		cout << "扩容" << s2.capacity() << endl;
	//		old = s2.capacity();
	//	}

	//}



	//string s3("hello world");
	//s3.resize(5);//即reserve的size
	//cout << s3 << endl;//与前面不同，这里是对原数据进行删除
	//cout << s3.capacity() << endl;
	//cout << s3.size() << endl;


	//string s4;
	//s4.resize(5, '#');//空就给你开
	//cout << s4 << endl;


	////两种访问
	//s3[0]++;
	//s4.at(0)++;//是圆括号
	//cout << s4.at(0)++ << endl;


	//插入删除等
	//string s6("bit");
	//string s5("world");
	//s5.push_back('#');//也可以用++，+=
	//s5.append("hello");//append函数可以添加一个元素或者一个容器，而push_back函数只能添加一个元素
	//s5.append(s6);
	//cout << s5 << endl;

	//string str("xxxxxxx");
	//string base = "The quick brown fox jumps over a lazy dog";
	//str.assign(base);//用来给一个容器分配新的内容，替换原来的内容
	//cout << str << endl;

	//str.assign(base, 5, 10);//从第五个后面开始打印10个(不包含第五个）
	//cout << str << endl;

	////insert,erase,replace能不用就不用，涉及挪动数据效率不高
	//string str2("hello world");
	//str2.insert(0, 1, '#');
	//cout << str2 << endl;
	//str2.insert(str2.begin(), 'x');
	//cout << str2 << endl;
	//str2.erase(5);//只保留前5个
	//cout << str2 << endl;


	//string str3("hello world");
	//str3.replace(5, 3, "#$20");//把第5个后面的3个字符删掉，并改为#$20
	//cout << str3 << endl;
	//printf("%p\n", str3.c_str());
}


////4.2string的其他内置函数
//void test_string6()
//{
//	string s1("test.cpp.#.yvlong");
//	size_t i = s1.rfind('.');//从后往前找.的第一个下标
//	cout << i << endl;
//	string s2 = s1.substr(i);//打印该下标之后的,也会把这个下标打印出来,即i给出了起始打印的位置
//	cout << s2 << endl;
//
//
//	string s3("ftp://www.baidu.com/?tn=65081411_1_oem_dg");
//	// 协议
//	// 域名
//	// 资源名
//
//	string sub1, sub2, sub3;
//	size_t i1 = s3.find(':');//找不到的话i1会被设置为npos
//	if (i1 != string::npos)
//		sub1 = s3.substr(0,i1);//两个参数即给出了起始打印的位置和打印的个数
//	else
//		cout << "没有找到i1" << endl;
//
//	size_t i2 = s3.find('/', i1 + 3);
//	if (i2 != string::npos)
//		sub2 = s3.substr(i1 + 3, i2 - (i1 + 3));
//	else
//		cout << "没有找到i2" << endl;
//
//	sub3 = s3.substr(i2 + 1);
//
//	cout << sub1 << endl;
//	cout << sub2 << endl;
//	cout << sub3 << endl;
//}

void test_string7()
{

	/*	string s1, s2;
		cin >> s1 >> s2;
		cout << s1 << endl;
		cout << s2 << endl;*///如果字符中本身包含空格或者换行会没办法打印完全


		string str;
		getline(cin, str, '!');//读取！之前的（不包括！）
		/*cout << str;*/

	/*	size_t i = str.rfind(' ');
		if (i != string::npos)
		{
			cout << str.size() - (i + 1) << endl;
		}
		else
		{
			cout << str.size() << endl;
		}*/


}
void test_string8()
{
	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::size_t found = str.find_first_not_of("abc");//找到第一个出现的不是a或者b,c,d，返回下标
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_not_of("abc", found + 1);//从下一个位置接着找
	}

	std::cout << str << '\n';

	//std::string str("Please, replace the vowels in this sentence by asterisks.");
	//std::size_t found = str.find_first_of("abcd");//找到第一个出现的a或者b,c,d，返回下标
	//while (found != std::string::npos)
	//{
	//	str[found] = '*';
	//	found = str.find_first_of("abcd", found + 1);//从下一个位置接着找
	//}

	//std::cout << str << '\n';
}
int main()
{
	test_string8();
	return 0;
}