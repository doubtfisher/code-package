#pragma once
#include <iostream>

using std::cout;
using std::endl;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K,V>* _parent;

	std::pair<K, V> _kv;
	int _bf;//平衡因子

	AVLTreeNode(const std::pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
				
			}
			else if (cur->_kv.first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
			}

			if (parent->_bf == 0)//平衡因子为0，说明此时高度不变，更新结束
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//高度变了，继续更新
			{
				cur=parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)//不平衡，需要进行旋转
			{
				//旋转的目的：把子树变为平衡，并且降高度
			    //左单旋
				//右单旋
				//双旋

				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//右边高，左单旋
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)//左边高，右左双旋
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == 1)
					{
						RotateLR(parent);//左右双旋
					}
					else if (cur->_bf == -1)
					{
						RotateR(parent);//右单旋
					}
				}
				break;
			}
		}
		return true;
	}

	void RotateL(Node* parent)//左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL!=nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* pparent = parent->_parent;//先保存一份
		parent->_parent = subR;

		if (parent == _root)//当parent是根节点时
		{
			_root = subR;
		}
		else//当parent不是根节点时
		{
			if (pparent->_left = parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
		}

		subR->_parent = pparent;//更新subR的父节点
		subR->_bf = parent->_bf = 0;//旋转之后，更新subR和parent的平衡因子
	}

	void RotateR(Node* parent)//右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR != nullptr)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (pparent->_left == parent)//判断parent是否为根节点
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}

		subL->_parent = pparent;//更新subL的父节点
		subL->_bf = parent->_bf = 0;//旋转之后，更新subL和parent的平衡因子
	}

	 //通过旋转，我们发现，b和c最终会成为30的左边和90的右边
	//当在b的位置插入一个节点时，30的平衡因子会变成0, 90的平衡因子会变成1。
	//当在c的位置插入一个节点时，30的平衡因子会变成 - 1, 90的平衡因子会变成0。

	void RotateLR(Node* parent)//左右双旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);//先左旋
		RotateR(parent->_right);//再右旋
		
		//双旋需要处理的是平衡因子
		if (bf == 1)//意味着在c的位置插入了一个节点
		{
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)//在b的位置插入了一个节点
		{
			parent->_bf = 1;
			subL->_bf = 0;
		}
		else if (bf == 0)//插入一个节点之后，只有三个节点
		{
			subL->_bf = parent->_bf = 0;
		}
	}

	void RotateRL(Node* parent)//右左双旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);//右单旋
		RotateL(parent);//左单旋

		//旋转之后，更新平衡因子
		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = subR->_bf = 0;
		}
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
	
	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		if (rightHeight - leftHeight != _root->_bf)
		{
			cout << "平衡因子异常" << endl;
			return false;
		}

		return abs(leftHeight - rightHeight) < 2
			   &&_IsBalance(root->_left)
			   &&_IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}


private:
	Node* _root;

};

