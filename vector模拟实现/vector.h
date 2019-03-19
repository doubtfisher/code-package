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
	const_iterator begin()const//const������
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
	Vector(const Vector<T>& v)//��������
	{
		//����ʹ��memcpy(memcpy��ǳ����)
		_start = new T[v.Capacity()];
		for (size_t i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endofstorage = _start + v.Capacity();

	}

	//copy=v
	Vector<T>& operator=(Vector<T> v)//��ֵ(�ִ�д��)
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
				//memcpy(_start, tmp, sizeof(T)*size);//memcpy��ǳ���������vector��������string��Ķ���ǳ�����ص���ָ��ָ��Ŀռ䱻�ͷ����Σ�������Ҫ���
				//�ʺ��������͵Ŀ���
				for (size_t i = 0; i <size; i++)//���ֽڿ���
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
			if (n < Size())//��С
			{
				_finish = _start + n;
			}
			else//���
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

	void PushBack(const T& x)//β��
	{
		CheckCapacity();
		*_finish = x;
		 _finish++;

		//Insert(end(), x);
	}
	void PopBack()//βɾ
	{
		/*if (Size()>0)
		    _finish--;*/
		Erase(_finish - 1);
	}
	void Insert(iterator pos, const T& x)
	{
		size_t n = pos - _start;//���ݺ���һ��ȫ�µĿռ䣬��pos��ָ��ɵĿռ䣬������Ҫ����һ��pos
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

