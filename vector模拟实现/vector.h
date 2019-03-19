#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>

using namespace std;

template<class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}
	const_iterator begin()const//const迭代器
	{
		return _start;
	}
	const_iterator end()const
	{
		return _finish;
	}
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{}

	//copy(v)
	Vector(const Vector<T>& v)//拷贝构造
	{
		//不能使用memcpy(memcpy是浅拷贝)
		_start = new T[v.Capacity()];
		for (size_t i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endofstorage = _start + v.Capacity();

	}

	//copy=v
	Vector<T>& operator=(Vector<T> v)//赋值(现代写法)
	{
		this->Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofstorage, v._endofstorage);
	}
	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			int size = Size();
			T* tmp = new T[n];
			if (_start)
			{
				//memcpy(_start, tmp, sizeof(T)*size);//memcpy是浅拷贝，如果vector里面存的是string类的对象，浅拷贝回导致指针指向的空间被释放两次，所以需要深拷贝
				//适合所有类型的拷贝
				for (size_t i = 0; i <size; i++)//按字节拷贝
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
		
			_start = tmp;
			_finish = _start + size;
			_endofstorage = _start + n;
		}
	}
	
	void CheckCapacity()
	{
		if (_finish >= _endofstorage)
		{
			int newcapacity = Capacity() == 0 ? 5 : Capacity() * 2;
			T* ptmp = new T[newcapacity];
			int size = Size();
			if (_start != nullptr)
			{
				memcpy(ptmp, _start, sizeof(T)*size);
				delete[] _start;
			}
			_start = ptmp;
			_finish = _start + size;
			_endofstorage = _start + newcapacity;
		}
	}

	void Resize(size_t n,const T&val=T())
	{
		if (n > Capacity())
		{
			if (n < Size())//缩小
			{
				_finish = _start + n;
			}
			else//变大
			{
				while (_finish <_start + n)
				{
					_finish = val;
					_finish++;
				}
			}
		}
	}
	size_t Size()const
	{
		return _finish - _start;
	}

	size_t Capacity()const
	{
		return _endofstorage - _start;
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos)const
	{
		assert(pos < Size());
		return _start[pos];
	}

	void PushBack(const T& x)//尾插
	{
		CheckCapacity();
		*_finish = x;
		 _finish++;

		//Insert(end(), x);
	}
	void PopBack()//尾删
	{
		/*if (Size()>0)
		    _finish--;*/
		Erase(_finish - 1);
	}
	void Insert(iterator pos, const T& x)
	{
		size_t n = pos - _start;//扩容后，是一个全新的空间，而pos还指向旧的空间，所以需要重置一下pos
		if (_finish == _endofstorage)
		{
			size_t newcapacity = Capacity() == 0 ? 5 : Capacity() * 2;
			Reserve(newcapacity);
		}
		pos = _start + n;
		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			end--;
		}
		//_start[pos] = x;
		*pos = x;
		_finish++;
	}
	void Erase(iterator pos)
	{
		assert(pos < _finish&&pos >= _start);
		iterator cur = pos+1;
		while (cur!=_finish)
		{
			*(cur - 1) = *cur;
			cur++;
		}
		_finish--;
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
	}
private:
	iterator _start;
	iterator _finish;
	iterator _endofstorage;
};

