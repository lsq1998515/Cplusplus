
#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <list>
#include <iostream>
using namespace std;


//typedef basic_string<char> string;
//string是模板basic_string的一个实例 

/* 构造
//default (1)
//string();
//copy(2)
//string(const string& str);
//substring(3)
//string(const string& str, size_t pos, size_t len = npos);
//from c - string(4)
//string(const char* s);
//from sequence(5)
//string(const char* s, size_t n);
//fill(6)
//string(size_t n, char c);
//range(7)
//template <class InputIterator>
//string(InputIterator first, InputIterator last); 
*/


void testString1()
{
	//string s;
	//string s2("hello world");//hello world
	//string copy(s2);//hello world
	//string s3(s2, 0, 5);//hello
	//string s4("hello world", 2);//he
	//string s5(10, 'a');//aaaaaaaaaa

	//char str1[] = "china";
	//char str2[] = "中国";
	//cout << sizeof(str1) << endl;//5个字符+'/0'
	//cout << sizeof(str2) << endl;//一个汉字占两个字节+ '/0'
	//cout << str1 << endl;
	//cout << str2 << endl;
	char str3[5];
	str3[0] = -42;
	str3[1] = -48;
	str3[2] = -71;
	str3[3] = -6;
	str3[4] = 0;
	cout << str3 << endl;//中国
}

void testiterator()//测试迭代器
{
	//使用接口: iterator begin();
	string s2("hello world");
	/*
		迭代器:一种容器内容的访问机制  可读可写的
		使用方法:类似于指针的使用方式 但是不等于指针  无论怎么样迭代器都是解引用然后,进行前置++;
		begin迭代器:指向容器的第一个元素的位置
		end迭代器: 指向容器的最后一个元素的下一个位置
		左闭右开: [begin , end)
	*/

	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//反向迭代器
	//rbegin:返回最后一个元素的位置
	//rend: 返回第一个元素 前面的位置
	//仍然是左闭右开
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;


	//普通for
	for (int i = 0; i < s2.size();++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	//范围for底层实现:使用迭代器
	for (const auto& b:s2)
	{
		cout << b << " ";
	}
	cout << endl;

	/*list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	list<int>::iterator lit = l.begin();
	while (lit != l.end())
	{
	cout << *lit << " ";
	++lit;
	}
	cout << endl;*/

	//使用接口: const_iterator begin() const;
	const string s3("hello");
	string::const_iterator s3it = s3.begin();//const迭代器只可读,不可写
	while (s3it!=s3.end())
	{
		cout << *s3it << " ";
		++s3it;
	}
	cout << endl;

	//const类型的反向迭代器
	string::const_reverse_iterator cs3rit = s3.rbegin();
	while (cs3rit != s3.rend())
	{
		cout << *cs3rit << " ";
		++cs3rit;
	}
	cout << endl;
}




int main()
{
	
	//testString1();
	testiterator();
	system("pause");
	return 0;
}

