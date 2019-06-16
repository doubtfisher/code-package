#pragma once
#include <iostream>
using namespace std;

enum Color
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	std::pair<K, V> _kv;
	Color _col;//结点颜色

	RBTreeNode(const pair<K, V> kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_kv(kv)
		, _col(BLACK)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()//构造函数
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		//空树的情况
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		//不是空树的情况
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur ->_kv.first < kv.first)
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
		cur->_col = RED;//新插入的节点的颜色一定是红色

		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//平衡
		while (parent && parent->_col == RED)//因为插入的节点是红色，所以当parent的颜色是红色，才需要处理
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//第一种情况：直接变色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else//叔叔不存在 或者 叔叔存在且为黑
				{
					//第三种情况：先处理双旋，把双旋变成单旋  
					if (cur == parent->_right)//cur是parent的右，则是双旋
					{
						RotateL(parent);//左单旋   旋转之后，cur和parent的位置已经发生变化
						swap(cur, parent);
					}

					//第二种情况：单旋+变色
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
			else//parent==grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//第一种情况：直接变色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//先处理第三种情况：
					if (cur == parent->_left)//cur在parent的左边，就是双旋
					{
						RotateR(parent);//右单旋  
						swap(cur, parent);//调整cur和parent的位置
					}

					RotateL(grandfather);//左单旋
					parent->_col = BLACK;
					grandfather->_col = RED;
					
				}
			}
		}
		_root->_col = BLACK;//根节点永远是黑色的
		return true;
	}

	void RotateL(Node* parent)//左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;
		if (_root == parent)
		{
			_root = subR;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subR;
			else
				ppnode->_right = subR;
		}
		subR->_parent = ppnode;
	}

	void RotateR(Node* parent)//右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
		}
		subL->_parent = ppnode;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	


private:
	Node* _root = nullptr;
};