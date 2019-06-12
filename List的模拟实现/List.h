#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

//模板的实例化，是按需实例化

template <class T>
struct _ListNode
{
	T _data;
	_ListNode<T>* _prev;
	_ListNode<T>* _next;

	_ListNode(const T& x=T())
		:_data(x)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

template<class T,class Ref,class Ptr>
struct _ListIterator
{
	typedef _ListNode<T> Node;
	typedef _ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	_ListIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
		//return &(this->operator*());
	}

	//++it   it.operator++(&it)
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
};


template<class T>
class List
{
	typedef _ListNode<T> Node;
public:
	typedef _ListIterator<T,T&,T*> iterator;
	typedef _ListIterator<T,const T&,const T*> const_iterator;

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	//l2(l1)
	List(const List<T>& l)//链表的拷贝构造
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		//遍历l1，遇到一个结点，就把它拷贝到l2中
		const_iterator it = l.begin();
		while (it != l.end())
		{
			this->PushBack(*it);
			it++;
		}
	}

	//l1=l2;
	List<T>& operator=( List<T>& l)//operator 赋值的现代写法
	{
		swap(_head, l._head);
		return *this;

	}

	void PushBack(const T& x)
	{
		//Node* newnode = new Node(x);
		//Node* tail = _head->_prev;

		////tail  newnode  _head
		//tail->_next = newnode;
		//newnode->_prev = tail;
		//newnode->_next = _head;
		//_head->_prev = newnode;
		Insert(end(), x);

	}

	void PopBack()//尾删
	{
		Erase(--end());//end是最后一个数据的下一个位置
	}
	void PushFront(const T& x)//头插
	{
		Insert(begin(), x);
	}
	void PopFront()//头删
	{
		Erase(begin());
	}
	void Insert(iterator pos, const T& x)//在某个位置之前插入x
	{
		//prev  newnode  cur
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* newnode = new Node(x);
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}

	iterator Erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;
		delete cur;

		return iterator(next);
	}

	size_t Size()
	{
		size_t size = 0;
		for (const auto& e : *this)
		{
			size++;
		}
		return size;
	}

	bool Empty()//判断是否为空
	{
		return begin() == end();
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	void Clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

private:
	Node* _head;
};