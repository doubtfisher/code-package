#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//传统写法
namespace bit
{
	class String
	{
	public:

		//String()//无参构造函数
		//	:_str(new char[1])//开一个字节使用new是为了和后面delete[]对应起来
		//{
		//	_str[0] = '\0';
		//}

		//String(char* str)//带参构造函数
		//	:_str(new char[strlen(str)+1])
		//{
		//	strcpy(_str, str);
		//}

		String(const char* str = "")//初始化
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//s3(s2)
		String(const String& s)//深拷贝
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		//s3=s2
		String& operator=(const String& s)//赋值
		{
			if (this != &s)
			{
				delete[] _str;//_str本身就指向一个空间，在拷贝的时候，不知道拷贝的内容大还是小，所以得先把_str指向的空间给释放掉，再去开辟一块合适大小的空间，这样会防止空间不够用，或者空间浪费问题
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		char* c_str()//返回c格式字符串
		{
			return _str;
		}

		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//返回pos位置的字符
		{
			return _str[pos];
		}

		~String()//清理
		{
			if (_str)
			{
				delete[] _str;
			}
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}

	private:
		char* _str;
	};

	void test()
	{
		String s1;
		String s2("hello");
		for (size_t i = 0; i < s2.Size(); i++)//遍历字符串
		{
			cout << s2[i] << " ";
		}
		cout << endl;
	}
}

//现代写法
namespace bit
{
	class String
	{
	public:
		String(const char* str = "")//初始化
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//s3(s2)
		String(const String& s)
			:_str(nullptr)
		{
			/*_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);*/
			//现代写法
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		//s3=s2
		String& operator=(const String& s)//赋值
		{
			if (this != &s)//防止自己跟自己赋值
			{
				//delete[] _str;//_str本身就指向一个空间，在拷贝的时候，不知道拷贝的内容大还是小，所以得先把_str指向的空间给释放掉，再去开辟一块合适大小的空间，这样会防止空间不够用，或者空间浪费问题
				//_str = new char[strlen(s._str) + 1];
				//strcpy(_str, s._str);
				String tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}

		char* c_str()//返回c格式字符串
		{
			return _str;
		}

		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//返回pos位置的字符
		{
			return _str[pos];
		}

		~String()//清理
		{
			if (_str)
			{
				delete[] _str;
			}
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}

	private:
		char* _str;
	};

	void test()
	{
		String s1;
		String s2("hello");
		for (size_t i = 0; i < s2.Size(); i++)//遍历字符串
		{
			cout << s2[i] << " ";
		}
		cout << endl;
	}
}
namespace bit//模拟实现string类
{
	class String
	{
	public:

		/*friend ostream& operator<<(ostream& out, const string& s);*/
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}
		typedef const char* const_iterator;
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		String(const char* str = "")//初始化
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//给\0预留一个空间
			strcpy(_str, str);
		}
		void Swap(String& s)
		{
			swap(this->_str, s._str);
			swap(this->_size, s._size);
			swap(this->_capacity, s._capacity);
		}
		//s2(s1)
		String(const String& s)//拷贝构造
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}
		//s1=s3
		String& operator=(String s)//赋值
		{
			this->Swap(s);
			return *this;
		}

		~String()//析构函数
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}
		size_t Size()//大小
		{
			return _size;
		}
		size_t Capacity()//容量
		{
			return _size;
		}
		void Reserve(size_t n)//扩容
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void Resize(size_t n,char ch='\0');
		char& operator[](size_t pos)//返回某个位置的字符
		{
			assert(pos < _size);
			return _str[pos];
		}

		char* c_str() const
		{
			return _str;
		}

		void PushBack(char ch)//尾插一个字符
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 15 : _capacity * 2;
				Reserve(newcapacity);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void PopBack()//尾删一个字符
		{
			assert(_size > 0);
			_size--;
			_str[_size] = '\0';
		}
		void Append(const char* str)//追加一个字符串
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				Reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		//s1+'a'
		String& operator+=(char ch)//尾上追加一个字符
		{
			PushBack(ch);
			return *this;
		}
		String& operator+=(const char* str)//尾上追加一个字符串
		{
			Append(str);
			return *this;
		}
		size_t Find(char ch,size_t pos=0)//从前往后查找一个字符,返回的是下标
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t RFind(char ch,size_t pos=npos)//从后往前查找一个字符
		{
			size_t i = (pos== npos ? _size : pos + 1);
			for (; i >0; i--)
			{
				if (_str[i-1] == ch)
				{
					return i-1;
				}
			}
			return npos;
		}

		String Substr(size_t pos, size_t len)//在一个字符串中找一个子串
		{
			String s;
			while (pos < _size && len--)
			{
				s += _str[pos++];
			}
			return s;
		}

		size_t Find(char* str,size_t pos=0)//找一个字符串
		{
			const char* start = strstr(_str+pos, str);
			if (start)
			{
				return start - _str;
			}
			else
			{
				return npos;
			}
		}

		void Insert(size_t pos, char ch)//在某个位置插入一个字符
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
			size_t	newcapacity = _capacity == 0 ? 15 : _capacity * 2;
			Reserve(newcapacity);
			}
			size_t end = _size;
			while (end > pos)
			{
				_str[end] = _str[end-1];
				end--;
			}
			_str[pos] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void Insert(size_t pos, const char* str)//在某个位置插入一个字符串
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				Reserve(_size + len);
			}
			size_t end = _size;
			while (end > pos)
			{
				_str[end+len-1] = _str[end - 1];
				end--;
			}
			while (*str)
			{
				_str[pos++] = *str++;
			}
			_size+=len;
			_str[_size] = '\0';
		}
		void Erase(size_t pos, size_t len)//删除len个字符
		{
			assert(_size > 0);
			if (pos + len >= _size)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				for (size_t i = pos + len; i < _size; i++)
				{
					_str[pos++] = _str[i];
				}
				_size -= len;
				_str[_size] = '\0';
			}
		}
	
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};

  const size_t String::npos = -1;
	String operator+(const String& s1, String& s2)//代价太大，不建议使用
	{
		String s = s1;
		s += s2.c_str();
		return s;
	}
	String operator+(const String& s1, const char* str)
	{
		String s = s1;
		s += str;
		return s;
	}
	ostream& operator<<(ostream& out, const String& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	void TestString1()
	{
		String s1("hello");
		for (size_t i = 0; i < s1.Size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		String::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			cout << *it1<< " ";
			it1++;
		}
		cout << endl;

		for (auto ch : s1)//基于范围的for循环是由迭代器支撑的
		{
			cout << ch << " ";
		}
	}
	void TestString2()
	{
		String s;
		s.PushBack(' ');
		s.Append("hello");
		s.PushBack(' ');
		s.Append("world");
		s.PushBack(' ');
		s.Append("world");
		s += 'y';
		s += "!!!";

		for (size_t i = 0; i < s.Size(); i++)
		{
			cout << s[i] << " ";
		}
		cout <<s<< endl;//重载输出
		String file("test.cpp");
		size_t pos = file.RFind('.');
		cout << file.Substr(pos,5)<< endl;
	}
	void TestString3()
	{
		String s = "hello";
		s.Insert(0, ' ');
		s += "word";
		s.Insert(6, ' ');
		cout << s << endl;

		s.Insert(6, "bit");
		cout << s << endl;

		s.Erase(6, 3);
		cout << s << endl;

		s.Erase(6, 15);
		cout << s << endl;
	}
}
