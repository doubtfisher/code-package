#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class String
{
public:
	//String()//无参构造
	//	:_str(new char[1])
	//{
	//	_str = '\0';//如果传的是空串的话，里面还有一个‘\0’,保证解引用后,程序不会崩
	//}
	//
	String(const char* str = "")//带参构造
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);//strcpy会自动把\0拷过去
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////

	//s3(s2);
	String(const String& s)//传统的深拷贝
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
	////s3(s2);
	String(const String& s)//现代的深拷贝
		:_str(nullptr)//把s3的_str初始化为空，当tmp和s._str交换后，tmp出了作用域后调析构函数
	{
		String tmp(s._str);
		swap(_str, s._str);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////

	//s3=s2;
	String& operator=(const String& s)//传统的赋值
	{
		if (this != &s)//防止自己给自己赋值
		{
			delete[] _str;//为了防止内存泄漏，先把s3一开始的空间给释放掉，再拷一份和s2一样大小的空间进行赋值运算
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	//s3=s2;
	String& operator=(const String& s)//现代的赋值
	{
		if (this != &s)
		{
			String tmp(s._str);
			swap(_str, s._str);//交换后，tmp是s3原来的那块空间，出了作用域会自动调析构函数进行释放
		}
		return *this;
	}
	//s3=s2;
	String& operator=(String s)//更简洁的赋值
	{
		swap(_str, s._str);
		return *this;
	}

	size_t Size()
	{
		return strlen(_str);
	}

	char& operator[](size_t pos)
	{
		return _str[pos];
	}

	char* c_str()
	{
		return _str;
	}


	~String()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
private:
	char* _str;
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

//传统的深拷贝：直观
//现代的深拷贝：简洁+复用

//写时拷贝
string operator+(const string& s1, const string& s2)
{
	string ret;
	ret.reserve(s1.size() + s2.size());//开辟s1+s2大小的空间
	ret.append(s1);//把s1追加到ret的后面
	ret.append(s2);//把s2追加到ret的后面

	return ret;//当返回ret时，会生成一个临时对象，临时对象又会被拷贝构造赋给最终返回的对象，中间会多了两次拷贝构造，而且一出函数，这两次拷贝构造就会被释放掉，这样的话，代价太大
}

//因为深拷贝的实现代价很大，在有些时候，使用写时拷贝来替代深拷贝，写时拷贝采用了引用计数的方式，确保某块空间只被释放一次。

//写时拷贝是一种拖延症，是在浅拷贝的基础之上增加了引用计数的方式来实现的。
//引用计数：用来记录资源使用者的个数。在构造时，将资源的计数给成1，每增加一个对象使用该资源，就给
//计数增加1，当某个对象被销毁时，先给该计数减1，然后再检查是否需要释放资源，如果计数为1，说明该
//对象时资源的最后一个使用者，将该资源释放；否则就不能释放，因为还有其他对象在使用该资源。

//写时拷贝又称为延迟拷贝，只有在写的时候，才发生拷贝。写时拷贝虽然效率高，但是因为存在线程安全问题，所以用的也不是很多

