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

	//˼·������
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

	//��Ϊ�գ�����ָ����
    //��Ϊ�գ�����ָ����
	//���Ҷ���Ϊ�գ�������ڵ�(���������ҽڵ��������������ڵ�)�������ɾ�����������ҽڵ��������������ڵ�
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
				//�ҵ��ˣ���ʼɾ��
				if (cur->_left == nullptr)//1.��Ϊ�գ�����ָ��������
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
				else if (cur->_right == nullptr)//2.��Ϊ�գ�����ָ��������
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
				else//3.���Ҷ���Ϊ�գ�������ڵ㣬��ɾ������ڵ�
				{
					Node* preplace = cur;//��������ؼ��㣬������ڵ�ֱ��������ڵ�ʱ�������ѭ������ʱ������ڵ�ĸ��׾Ͳ��ܳ�ʼ��Ϊnullptr������Ҫ�ó�Ҫɾ���Ľڵ�cur
					Node* replace = cur->_right;
					while (replace->_left)
					{	
						 preplace = replace;
						 replace = replace->_left;
					}
					cur->_kv = replace->_kv;

					del = replace;
					//ɾ������ڵ������ڵ�
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

