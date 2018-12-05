#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//��ͳд��
namespace bit
{
	class String
	{
	public:

		//String()//�޲ι��캯��
		//	:_str(new char[1])//��һ���ֽ�ʹ��new��Ϊ�˺ͺ���delete[]��Ӧ����
		//{
		//	_str[0] = '\0';
		//}

		//String(char* str)//���ι��캯��
		//	:_str(new char[strlen(str)+1])
		//{
		//	strcpy(_str, str);
		//}

		String(const char* str = "")//��ʼ��
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//s3(s2)
		String(const String& s)//���
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		//s3=s2
		String& operator=(const String& s)//��ֵ
		{
			if (this != &s)
			{
				delete[] _str;//_str�����ָ��һ���ռ䣬�ڿ�����ʱ�򣬲�֪�����������ݴ���С�����Ե��Ȱ�_strָ��Ŀռ���ͷŵ�����ȥ����һ����ʴ�С�Ŀռ䣬�������ֹ�ռ䲻���ã����߿ռ��˷�����
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		char* c_str()//����c��ʽ�ַ���
		{
			return _str;
		}

		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//����posλ�õ��ַ�
		{
			return _str[pos];
		}

		~String()//����
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
		for (size_t i = 0; i < s2.Size(); i++)//�����ַ���
		{
			cout << s2[i] << " ";
		}
		cout << endl;
	}
}

//�ִ�д��
namespace bit
{
	class String
	{
	public:
		String(const char* str = "")//��ʼ��
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
			//�ִ�д��
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		//s3=s2
		String& operator=(const String& s)//��ֵ
		{
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				//delete[] _str;//_str�����ָ��һ���ռ䣬�ڿ�����ʱ�򣬲�֪�����������ݴ���С�����Ե��Ȱ�_strָ��Ŀռ���ͷŵ�����ȥ����һ����ʴ�С�Ŀռ䣬�������ֹ�ռ䲻���ã����߿ռ��˷�����
				//_str = new char[strlen(s._str) + 1];
				//strcpy(_str, s._str);
				String tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}

		char* c_str()//����c��ʽ�ַ���
		{
			return _str;
		}

		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//����posλ�õ��ַ�
		{
			return _str[pos];
		}

		~String()//����
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
		for (size_t i = 0; i < s2.Size(); i++)//�����ַ���
		{
			cout << s2[i] << " ";
		}
		cout << endl;
	}
}
namespace bit//ģ��ʵ��string��
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
		String(const char* str = "")//��ʼ��
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//��\0Ԥ��һ���ռ�
			strcpy(_str, str);
		}
		void Swap(String& s)
		{
			swap(this->_str, s._str);
			swap(this->_size, s._size);
			swap(this->_capacity, s._capacity);
		}
		//s2(s1)
		String(const String& s)//��������
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}
		//s1=s3
		String& operator=(String s)//��ֵ
		{
			this->Swap(s);
			return *this;
		}

		~String()//��������
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}
		size_t Size()//��С
		{
			return _size;
		}
		size_t Capacity()//����
		{
			return _size;
		}
		void Reserve(size_t n)//����
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
		char& operator[](size_t pos)//����ĳ��λ�õ��ַ�
		{
			assert(pos < _size);
			return _str[pos];
		}

		char* c_str() const
		{
			return _str;
		}

		void PushBack(char ch)//β��һ���ַ�
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
		void PopBack()//βɾһ���ַ�
		{
			assert(_size > 0);
			_size--;
			_str[_size] = '\0';
		}
		void Append(const char* str)//׷��һ���ַ���
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
		String& operator+=(char ch)//β��׷��һ���ַ�
		{
			PushBack(ch);
			return *this;
		}
		String& operator+=(const char* str)//β��׷��һ���ַ���
		{
			Append(str);
			return *this;
		}
		size_t Find(char ch,size_t pos=0)//��ǰ�������һ���ַ�,���ص����±�
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

		size_t RFind(char ch,size_t pos=npos)//�Ӻ���ǰ����һ���ַ�
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

		String Substr(size_t pos, size_t len)//��һ���ַ�������һ���Ӵ�
		{
			String s;
			while (pos < _size && len--)
			{
				s += _str[pos++];
			}
			return s;
		}

		size_t Find(char* str,size_t pos=0)//��һ���ַ���
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

		void Insert(size_t pos, char ch)//��ĳ��λ�ò���һ���ַ�
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

		void Insert(size_t pos, const char* str)//��ĳ��λ�ò���һ���ַ���
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
		void Erase(size_t pos, size_t len)//ɾ��len���ַ�
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
	String operator+(const String& s1, String& s2)//����̫�󣬲�����ʹ��
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

		for (auto ch : s1)//���ڷ�Χ��forѭ�����ɵ�����֧�ŵ�
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
		cout <<s<< endl;//�������
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
