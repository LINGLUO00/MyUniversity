#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
////1.ģ�壺
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
//	// ʹ������������ʾ�������������������ⶨ�塣
//	//�����������Ͷ�����룬����ֵ������ļ��ͻᱨ��
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
//// ���� �� Vector
//// ���� �� Vector<T>
// ����˵ģ������
//
//int main()
//{
//    Vector<int> v;
//    return 0;
//}



//2.string��ʹ��
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
	////����string(forѭ���±���ʣ�
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	//��
	//	cout << s1[i] << " ";
	//}
	//cout << endl;
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	//д
	//	s1[i]++;
	//}
	//cout << s1 << endl;
	




	////����string(��������
	//string::iterator it = s1.begin();
	//while (it != s1.end())
	//{
	//	//��
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	//it = s1.begin();
	//while (it != s1.end())
	//{
		// д
	//	*it = 'a';
	//	++it;
	//}
	//cout << endl;
	//cout << s1 << endl;


	//////��������Χfor��
	//for (auto ch : s1)
	//{
	//	//��
	//	cout << ch << " ";
	//}
	//cout << endl;
	//for (auto& ch : s1)//�����Ƿ���s1�����ã���Ϊ��Χfor�Ǵ�s1,������ch��ch�ĸı䲻Ӱ��s1����������ch��Ϊs1�ı���
	//{
	//	//д
	//	cout << ++ch;
	//}
	//cout << endl;
	//cout << s1 << endl;

	//���ű���(�����autoΪstring::reverse_iterator 
	//auto rit = s1.rbegin();
	//while (rit != s1.rend())
	//{
	//	cout << *rit;
	//	rit++;
	//}
	//cout << endl;



}


////����const����Ҫ����const���͵ĵ���������Ϊ��ͨ�������ǿ���д��,Ȩ�ޱ��Ŵ���
//void func(const string& s)
//{
//	auto it = s.begin();//string::const_iterator it =s.begin();
//	while (it != s.end())
//	{
//		//��֧��д
//
//		/**it = 'a';*/
//		//ֻ�ܶ�
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


////3.string�ĸ��ִ���
//void test_string3()
//{
//	string s1("hello world");
//	string s2(s1);
//	cout << s2 << endl;
//	string s3(s1, 5, 4);//ɾȥǰ5����������4��
//	cout << s3 << endl;
//	string s4(s1, 5);//ɾȥǰ5����Ȼ���ӡ����
//	cout << s4 << endl;
//	string s5(10,'a');//����һ���ַ�������10��ֵ��ʼ��Ϊa
//	cout << s5 << endl;
//	string s6(s1, 6, s1.size() - 6);//ͬs3
//	cout << s6 << endl;
//	string s8(++s1.begin(), --s1.end());//��ӡ����
//	cout << s8 << endl;
//}
//int main()
//{
//	test_string3();
//	return 0;
//}


//4.1string�ĸ������ú���
void test_string5()
{
	//string s1("hello world");
	//cout << s1.size() << endl;//��ʵstringһ��ʼֻ��length������C��������������ϰ��
	////��size�����ڳ���STL֮��Ϊ�˼��ݼ����˺�STL�����󳤶ȵĺ���һ�����ֵ�size�������Ϳ��Է����ʹ����STL���㷨
	//cout << s1.length() << endl;
	//cout << s1.capacity() << endl;//�࿪��Ϊ��\0
	//s1.clear();//�����capacity,size�����������ַ�����С�ģ����capacity����
	//s1 += "hehe";
	//cout << s1 << endl;
	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;


	//string filename;
	//cin >> filename;
	//FILE* fout = fopen(filename.c_str(), "r");//����ֻдfilename,��Ϊc�Ľӿڲ���ʶ,ʹ��c_str������c

	//string s2;
	//s2.reserve(10);//��ǰ���ռ�,capacityʵ��Ϊ16����Ϊ����ӡ���û������ܴ������Ч�ַ�
	//size_t old = s2.capacity();
	//cout << "��ʼ" << s2.capacity() << endl;
	//for (int i = 0; i < 100; i++)
	//{
	//	s2.push_back('x');
	//	if (s2.capacity() != old)
	//	{
	//		cout << "����" << s2.capacity() << endl;
	//		old = s2.capacity();
	//	}

	//}



	//string s3("hello world");
	//s3.resize(5);//��reserve��size
	//cout << s3 << endl;//��ǰ�治ͬ�������Ƕ�ԭ���ݽ���ɾ��
	//cout << s3.capacity() << endl;
	//cout << s3.size() << endl;


	//string s4;
	//s4.resize(5, '#');//�վ͸��㿪
	//cout << s4 << endl;


	////���ַ���
	//s3[0]++;
	//s4.at(0)++;//��Բ����
	//cout << s4.at(0)++ << endl;


	//����ɾ����
	//string s6("bit");
	//string s5("world");
	//s5.push_back('#');//Ҳ������++��+=
	//s5.append("hello");//append�����������һ��Ԫ�ػ���һ����������push_back����ֻ�����һ��Ԫ��
	//s5.append(s6);
	//cout << s5 << endl;

	//string str("xxxxxxx");
	//string base = "The quick brown fox jumps over a lazy dog";
	//str.assign(base);//������һ�����������µ����ݣ��滻ԭ��������
	//cout << str << endl;

	//str.assign(base, 5, 10);//�ӵ�������濪ʼ��ӡ10��(�������������
	//cout << str << endl;

	////insert,erase,replace�ܲ��þͲ��ã��漰Ų������Ч�ʲ���
	//string str2("hello world");
	//str2.insert(0, 1, '#');
	//cout << str2 << endl;
	//str2.insert(str2.begin(), 'x');
	//cout << str2 << endl;
	//str2.erase(5);//ֻ����ǰ5��
	//cout << str2 << endl;


	//string str3("hello world");
	//str3.replace(5, 3, "#$20");//�ѵ�5�������3���ַ�ɾ��������Ϊ#$20
	//cout << str3 << endl;
	//printf("%p\n", str3.c_str());
}


////4.2string���������ú���
//void test_string6()
//{
//	string s1("test.cpp.#.yvlong");
//	size_t i = s1.rfind('.');//�Ӻ���ǰ��.�ĵ�һ���±�
//	cout << i << endl;
//	string s2 = s1.substr(i);//��ӡ���±�֮���,Ҳ�������±��ӡ����,��i��������ʼ��ӡ��λ��
//	cout << s2 << endl;
//
//
//	string s3("ftp://www.baidu.com/?tn=65081411_1_oem_dg");
//	// Э��
//	// ����
//	// ��Դ��
//
//	string sub1, sub2, sub3;
//	size_t i1 = s3.find(':');//�Ҳ����Ļ�i1�ᱻ����Ϊnpos
//	if (i1 != string::npos)
//		sub1 = s3.substr(0,i1);//������������������ʼ��ӡ��λ�úʹ�ӡ�ĸ���
//	else
//		cout << "û���ҵ�i1" << endl;
//
//	size_t i2 = s3.find('/', i1 + 3);
//	if (i2 != string::npos)
//		sub2 = s3.substr(i1 + 3, i2 - (i1 + 3));
//	else
//		cout << "û���ҵ�i2" << endl;
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
		cout << s2 << endl;*///����ַ��б�������ո���߻��л�û�취��ӡ��ȫ


		string str;
		getline(cin, str, '!');//��ȡ��֮ǰ�ģ�����������
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
	std::size_t found = str.find_first_not_of("abc");//�ҵ���һ�����ֵĲ���a����b,c,d�������±�
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_not_of("abc", found + 1);//����һ��λ�ý�����
	}

	std::cout << str << '\n';

	//std::string str("Please, replace the vowels in this sentence by asterisks.");
	//std::size_t found = str.find_first_of("abcd");//�ҵ���һ�����ֵ�a����b,c,d�������±�
	//while (found != std::string::npos)
	//{
	//	str[found] = '*';
	//	found = str.find_first_of("abcd", found + 1);//����һ��λ�ý�����
	//}

	//std::cout << str << '\n';
}
int main()
{
	test_string8();
	return 0;
}