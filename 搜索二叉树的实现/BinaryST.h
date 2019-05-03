#pragma once
#include <iostream>
using namespace std;

template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	std::pair<K, V> _kv;

	BSTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
	{}
};

template<class K,class V>

class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	//思路分析：
	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (cur->_kv.first >kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if(cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	Node* Find(const K& k)
	{
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first < k)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first>k)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	//左为空，父亲指向右
    //右为空，父亲指向左
	//左右都不为空，找替代节点(左树的最右节点或者右树的最左节点)，最后再删除左树的最右节点或者右树的最左节点
	bool Erase(const K& k)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < k)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first>k)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				Node* del = cur;
				//找到了，开始删除
				if (cur->_left == nullptr)//1.左为空，父亲指向右子树
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr)//2.右为空，父亲指向左子树
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_left = cur->_left;
						}
					}
				}
				else//3.左右都不为空，找替代节点，并删除替代节点
				{
					Node* preplace = cur;//特殊情况关键点，当替代节点直接是最左节点时，不会进循环，这时候替代节点的父亲就不能初始化为nullptr，而是要置成要删除的节点cur
					Node* replace = cur->_right;
					while (replace->_left)
					{	
						 preplace = replace;
						 replace = replace->_left;
					}
					cur->_kv = replace->_kv;

					del = replace;
					//删除替代节点的最左节点
					if (preplace->_left == replace)
					{
						preplace->_left = replace->_right;
					}
					else
					{
						preplace->_right = replace->_right;
					}
				}
				delete del;
				return true;
			}
		}

		return false;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_kv.first <<" ";
		_Inorder(root->_right);
	}

	void Inorder()
	{
		_Inorder(_root);
	}

private:
	Node* _root;
};

void test_BSTree()
{
	BSTree<int,int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.Inorder();
	cout << endl;

	t.Erase(2);
	t.Erase(8);
	t.Erase(2);
	t.Erase(1);
	t.Erase(5);
	t.Erase(7);

	t.Inorder();

	for (auto e : a)
	{
		t.Erase(e);
	}

	cout << endl;
	t.Inorder();
}

