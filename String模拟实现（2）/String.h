#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <assert.h>


using namespace std;

class String
{
public:
	friend ostream& operator<<(ostream& out, const String& s);//��Ԫ

	typedef char* iterator;//�����Լ�ʵ�ֵĵ�����Ӧ���Ǵ�д��Iterator������������ʽforѭ��Ҫ������ǰ�����Ĺ淶�ߣ����Բ�ʵ��ΪСд��
	
	typedef char* const_iterator;

	iterator begin()//������
	{
		return _str;
	}
	iterator end()//������
	{
		return _str + _size;
	}

	const_iterator begin()const//������
	{
		return _str;
	}
	const_iterator end()const//������
	{
		return _str + _size;
	}

	String(char* str="")
	{
		_size = strlen(str);
		_capacity = _size;

		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}

	//s1.Swap(s2)
	void Swap( String& s)
	{
		swap(this->_str, s._str);
		swap(this->_size, s._size);
		swap(this->_capacity, s._capacity);
	}
	//s3(s2)
	String(const String& s)//�ִ���������
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}

	
	String& operator=( String s)//operator��ֵ
	{
		//if (this != &s)//��ֹ�Լ����Լ���ֵ
		//{
		//	delete[] _str;
		//	_str = new char[strlen(s._str) + 1];
		//	strcpy(_str, s._str);
		//}
		//return *this;

		this->Swap(s);
		return *this;

	}

	char* c_str()//����c��ʽ���ַ���
	{
		return _str;
	}

	size_t Size()//��С
	{
		return _size;
	}

	size_t Capacity()//����	
	{
		return _capacity;
	}

	void Reserve(size_t n)//����
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//������Ŀռ�tmp
			strcpy(tmp, _str);//��_str�ϵ����ݿ���tmp
			delete[] _str;//�ͷžɵĿռ�
			_str = tmp;//����_strָ���µĿռ�
			_capacity = n;
		}
	}

	void Resize(size_t n,char ch='\0')
	{
		if (n > _size)
		{
			if (n > _capacity)
			{
				Reserve(n);
			}
			memset(_str + _size, ch, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}

	char& operator[](size_t pos)//operator[]
	{
		assert(pos < _size);
		return _str[pos];
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

	void PopBack()//ɾ��һ���ַ�
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
	String& operator+=(char ch)
	{
		PushBack(ch);

		return *this;
	}

	//s1+"hello"
	String& operator+=(const char*str)//׷��һ���ַ���
	{
		Append(str);

		return *this;
	}

	size_t Find(char ch,size_t pos=0)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (ch == _str[i])
			{
				return i;
			}
		}
		return npos;
	}

	size_t RFind(char ch,size_t pos=npos)
	{
		size_t i = (pos == npos) ? _size : pos + 1;

		for (; i>0; i--)
		{
			if (ch == _str[i-1])
			{
				return i-1;
			}
		}
		return npos;
	}

	String Substr(size_t pos, size_t len)
	{
		String s;
		while (pos < _size&&len--)
		{
			s+= _str[pos++];
		}
		return s;
	}

	size_t Find(const char* str,size_t pos=0)//����һ���ַ���
	{
		char* start = strstr(_str+pos, str);
		if (start)
		{
			return start - _str;
		}
		else
		{
			return npos;
		}
	}
	
	void Insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		//1.�ж��Ƿ�����
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : _capacity * 2;
			Reserve(newcapacity);
		}
		size_t end = _size;
		while (end>pos)
		{
			_str[end-1+1] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size++;
		_str[_size] = '\0';

	}
	void Insert(size_t pos,const  char* str)//����һ���ַ���
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		else
		{
			size_t end = _size;
			while (end > pos)
			{
				_str[end-1+len] = _str[end-1];
				end--;
			}
			while (*str)
			{
				_str[pos++] = *str++;

			}
			_size += len;
			_str[_size] = '\0';
		}
	}

	void Erase(size_t pos, size_t len)//��posλ�ÿ�ʼ��ɾ������Ϊlen���ַ�
	{
		assert(pos <= _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t end = pos + len;
			while (end <_size)
			{
				_str[pos++] = _str[end++];
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}
	const static size_t npos;
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

const size_t String::npos = -1;

String operator+(const String& s1,  String& s2)
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