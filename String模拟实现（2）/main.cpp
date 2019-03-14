#include "String.h"

//void test1()
//{
//	String s1("hello world");
//	String s2(s1);
//	for (size_t i = 0; i < s2.Size(); i++)
//	{
//		cout << s2[i];
//	}
//	cout << endl;
//
//	String s3 = s2;
//	for (size_t i = 0; i < s3.Size(); i++)
//	{
//		cout << s3[i];
//	}
//	cout << endl;
//
//	String::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << "";
//		it1++;
//	}
//	cout << endl;
//
//	for (auto ch : s1)//本质上是由迭代器实现的
//	{
//		cout << ch << "";
//	}
//	cout << endl;
//}

//void test2()
//{
//	String s;
//	s.PushBack('I');
//	s.PushBack(' ');
//	s.Append("love");
//	s.PushBack(' ');
//	s.Append("code");
//	s.Append("code");
//	s.Append("code");
//
//	for (auto ch : s)
//	{
//		cout << ch << "";
//	}
//	cout << endl;
//}

//void test3()
//{
//	String s = "hello";
//	s += '\0';
//	s += "world";
//	String s1("hi");
//	cout<<s1 + "hello" << endl;
//	cout << s << endl;
//
//	string s1 = "yhx";
//	s1 += '\0';
//	s1 += "wsc";
//	cout << s1 << endl;
//}

//void test4()
//{
//	String file("file.cpp");
//	size_t pos = file.RFind('.');
//	cout << file.Substr(pos,4) << endl;
//
//	String url("http://www.baidu.com/");
//	size_t start = url.Find("://");
//	start += 3;
//	size_t finish = url.Find('/', start);
//	cout << url.Substr(start, finish - start)<<endl;
//}

void test5()
{
	String s = "hello";
	s += "world";
	s.Insert(5, ' ');
	s.Insert(11, ' ');
	s.Insert(12, "!!!");
	s.Erase(6, 3);
	cout << s << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}