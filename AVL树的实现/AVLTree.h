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
	int _bf;//ƽ������

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

		//����ƽ������
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

			if (parent->_bf == 0)//ƽ������Ϊ0��˵����ʱ�߶Ȳ��䣬���½���
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//�߶ȱ��ˣ���������
			{
				cur=parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)//��ƽ�⣬��Ҫ������ת
			{
				//��ת��Ŀ�ģ���������Ϊƽ�⣬���ҽ��߶�
			    //����
				//�ҵ���
				//˫��

				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//�ұ߸ߣ�����
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)//��߸ߣ�����˫��
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == 1)
					{
						RotateLR(parent);//����˫��
					}
					else if (cur->_bf == -1)
					{
						RotateR(parent);//�ҵ���
					}
				}
				break;
			}
		}
		return true;
	}

	void RotateL(Node* parent)//����
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL!=nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* pparent = parent->_parent;//�ȱ���һ��
		parent->_parent = subR;

		if (parent == _root)//��parent�Ǹ��ڵ�ʱ
		{
			_root = subR;
		}
		else//��parent���Ǹ��ڵ�ʱ
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

		subR->_parent = pparent;//����subR�ĸ��ڵ�
		subR->_bf = parent->_bf = 0;//��ת֮�󣬸���subR��parent��ƽ������
	}

	void RotateR(Node* parent)//�ҵ���
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
			if (pparent->_left == parent)//�ж�parent�Ƿ�Ϊ���ڵ�
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}

		subL->_parent = pparent;//����subL�ĸ��ڵ�
		subL->_bf = parent->_bf = 0;//��ת֮�󣬸���subL��parent��ƽ������
	}

	 //ͨ����ת�����Ƿ��֣�b��c���ջ��Ϊ30����ߺ�90���ұ�
	//����b��λ�ò���һ���ڵ�ʱ��30��ƽ�����ӻ���0, 90��ƽ�����ӻ���1��
	//����c��λ�ò���һ���ڵ�ʱ��30��ƽ�����ӻ��� - 1, 90��ƽ�����ӻ���0��

	void RotateLR(Node* parent)//����˫��
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);//������
		RotateR(parent->_right);//������
		
		//˫����Ҫ�������ƽ������
		if (bf == 1)//��ζ����c��λ�ò�����һ���ڵ�
		{
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)//��b��λ�ò�����һ���ڵ�
		{
			parent->_bf = 1;
			subL->_bf = 0;
		}
		else if (bf == 0)//����һ���ڵ�֮��ֻ�������ڵ�
		{
			subL->_bf = parent->_bf = 0;
		}
	}

	void RotateRL(Node* parent)//����˫��
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);//�ҵ���
		RotateL(parent);//����

		//��ת֮�󣬸���ƽ������
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
			cout << "ƽ�������쳣" << endl;
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

