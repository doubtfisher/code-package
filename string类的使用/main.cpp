#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void test1()
{
	string s1("hello");//构造
	cout << s1 << endl;

	string s2(s1);//拷贝构造
	cout << s2 << endl;

	string s3 = ("world");
     s3 = s2;//赋值
	 cout << s3 << endl;

	string file("file.cpp");
	string suffix(file, 4, 4);//构造函数
	cout << suffix << endl;

	string path("c:\\user",4);//构造函数
	cout << path << endl;

	string s5(file.begin(), file.end());//构造函数
	cout << s5 << endl;

	
}
//1.遍历字符串(以下标的形式访问)
int str2int1(string str)
{
	int value = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		value *= 10;
		value += str[i] - '0';//以下标的形式访问
		cout << str[i] <<" ";
	}
	cout << endl;
	return value;
	
}

//2.遍历字符串(以迭代器方式访问)//迭代器是指在不破坏封装的情况下去访问容器
int str2int2(string str)
{
	int value = 0;
	
	string::iterator it = str.begin();//正向迭代器
	while (it != str.end())
	{
		value *= 10;
		value += (*it - '0');
		it++;
	}

	vector<int> v;//vector的迭代器
	v.push_back(1);
	v.push_back(2);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;

	list<int> lt;//list的迭代器
	lt.push_back(10);
	lt.push_back(20);
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		lit++;
	}
	cout << endl;

	return value;
}

void test2()//反向迭代器
{
	string s6("12345");
	string::reverse_iterator rit = s6.rbegin();
	while (rit != s6.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}


//3.遍历字符串(新式for循环)
int str2int3(string str)
{
	int value = 0;

	for (auto ch : str)//c++11
	{
		value *= 10;
		value += (ch - '0');
	}
	return value;
}

int str2int4(const string& str)//const迭代器
{
	int value = 0;
	//string::const_iterator it = str.begin();
	//string::const_reverse_iterator rit = str.rbegin();

	auto it = str.crbegin();//c++11才支持cbegin和cend
	while (it != str.crend())
	{
		value *= 10;
		value += (*it - '0');
		it++;
	}

	return value;
}

void test3()
{
	string s1("hello");
	s1.push_back(' ');//插入一个字符
	s1.push_back('w');
	s1.push_back('o');
	s1.push_back('r');
	s1.push_back('l');
	s1.push_back('d');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1.max_size() << endl;

	string s;
	//size_t sz = s.capacity();
	//size_t sz = 0;
	s.resize(100);//会发生增容，会改变字符串的大小
	s.reserve(100);//reserve会避免增容，它是一次性把空间开好，之后都不会再发生增容，可以提高效率
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}

void test4()
{
	string s("hello world");
	cout << s.size() << endl;//11
	cout << s.capacity() << endl;//15
	//s.resize(5);
	//s.resize(14,'a');//当前位置比size大，需要有数据填充，如果给了，就填给的那个数，如果没给，就默认填'\0'
	//s.resize(14);
	//s.resize(20);
	cout << s << endl;
	//reserve:只把容量增上去，尽量增到string的整数倍处(只增容)
	//resize:
	//比当前size小时，数据减到当前size；
	//如果在当前size和容量之间，直接把数据个数增上去，中间填给的特殊字符；
	//如果比容量大，会先增容，然后填满现在的size,(增容+初始化)
}


void test5()//数据访问接口的使用
{
	string s1("hello,world");
	s1[5] = '%';//可以修改数据
	//cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ' ,')
		{
			s1[i] = '%';
		}
	}
	cout << s1 << endl;

	for (auto& ch : s1)
	{
		if (ch == '%')
		{
			ch = ',';
		}
	}
	cout << s1 << endl;


	size_t pos = s1.find(',');
	s1[pos] = '%';
	cout << s1 << endl;

	//at等价于operator[]
	s1.at(pos) = ',';
	cout << s1 << endl;
}

void test6()//常用接口
{
	string s1("hello");
	s1.push_back(' ');//尾上插入一个字符
	s1.append("world");//追加一个字符串
	s1 += "!!!";//+字符串，底层调的是append
	s1 += 'q';//+字符,在底层调的是push_back

	string protocol = "https://";
	string domain = "www.baidu.com";
	string url = protocol + domain;//对象+对象(不建议使用，代价太大)
	url += domain;//+对象
	cout << url << endl;

	s1.assign(" hei");//相当于operator赋值
	cout << s1 << endl;
}

void test7()//insert和erase接口
{
	//想在某个位置插入一个字符
	string s1("ello");
	s1.insert(0,1, 'h');//在0这个位置插入1个字符‘h’
	s1.insert(s1.begin(), 'h');//使用迭代器进行头插，一般不使用，效率太低
	s1.insert(0, "hello ");//插入字符串
	cout << s1 << endl;

	s1.erase(7, 1);//从下标为7的开始删除，删除一个
	s1.erase(4);//从4开始，往后的字符全部删掉
	cout << s1 << endl;
}
void test8()//两个string如何交换
{
	string s1("hello");
	string s2("world");
	s1.swap(s2);//成员变量的交换，代价小
	cout << s1 << "--" << s2 << endl;
	swap(s1, s2);//拷贝构造+多次赋值，都涉及到深浅拷贝的问题,代价很大，不建议用，效率太低
	cout << s1 << "--" <<s2<< endl;
}
void test9()//替换
{
	string url = "http://www.cplusplus.com/reference/string/string/clear/";
	url.replace(0, 4, "https");//把前四个字符替换为“https”
	cout << url << endl;
}

void test10()//C形式的字符串(遇到'\0'就结束)
{
	string url = "http://www.cplusplus.com/reference/string/string/clear/";
	cout << url.c_str() << endl;
	url[5] = '\0';
	printf("%s\n", url.c_str());
	cout << url << endl;
	cout << url.c_str() << endl;
}
void test11()//find系列
{
	//find  成功返回对应字符的位置，失败返回npos
	string str("file.cpp");
	string suffix(str, 4, 4);//太过生硬，不适合普遍的
	cout << suffix << endl;

	size_t pos = str.find('.');
	if (pos != string::npos)
	{
		string suffix(str, pos, str.size() - pos);//使用构造取后缀
		cout << suffix<< endl;
	}

}

string getfilesuffix(const string& file)//获取string的子串
{
	//size_t pos = file.find('.');
	//string suffix;
	//if (pos != string::npos)
	//{
	//	//suffix = file.substr(pos);
	//	//suffix = file.substr(pos, file.size() - pos);//从pos位置去找，找大小为len的字符
	//}

	size_t pos = file.rfind('.');
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);//从pos位置去找，找大小为len的字符
	}

	return suffix;
	
} 

void test12()
{
	//cout << getfilesuffix("file.hpp") << endl;
	cout << getfilesuffix("test.tar.zip") << endl;

}

void test13()//连续找后缀
{
	/*const string file("test.cpp.tar.zip");
	size_t pos = file.rfind('.');
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);
	}
	cout << suffix << endl;
	size_t prevpos = file.rfind('.', pos - 1);
	if (prevpos != string::npos)
	{
		suffix = file.substr(prevpos, pos - prevpos);
	}
	cout << suffix << endl*/;

   string url("http://cplusplus.com/reference/string/string/string/clear/");
   size_t pos = url.find("://");
   pos += 3;
   size_t finish = url.find('/', pos);
   string domain = url.substr(pos,finish-pos);
   cout << domain << endl;
}

int main()
{

	//test1();
	/*cout << str2int1("1234") << endl;
	cout << str2int2("1234") << endl;*/
	//test2();
	/*string s("1234");
	cout << str2int4(s) << endl;*/
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	//test11();
	//test12();
	test13();
	system("pause");
	return 0;
}

//string类中用的最多的接口有：构造、resize、reserve、operator[]、operator+=、insert、erase、swap、c_str、find、substr。