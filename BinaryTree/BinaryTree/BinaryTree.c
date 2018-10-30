#include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"



BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data= x;
	node->_left =NULL;
	node->_right = NULL;
	return node;
}


BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		(*pi)++;
		root->_left = BinaryTreeCreate(a, pi);
		(*pi)++;
		root->_right = BinaryTreeCreate(a, pi);

		return root;
	}
	else
	{
		return NULL;
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		           
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL
		&&root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) +
		BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) +
		BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	return ret = BinaryTreeFind(root->_right, x);
}

 void _BinaryTreePrevOrder(BTNode* root, int* a, int* pi)
{
	if (root == NULL)
	{
		return ;
	}
	printf("%c ", root->_data);
	(*pi)++;
	_BinaryTreePrevOrder(root->_left, a, pi);
	_BinaryTreePrevOrder(root->_right, a, pi);

}
void BinaryTreePrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
		return ;
	int treeSize = BinaryTreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*treeSize);
	int i = 0;
	_BinaryTreePrevOrder(root, arr, &i);

}

void _BinaryTreeInOrder(BTNode* root, int* arr, int* pi)
{
	if (root == NULL)
	{
		return ;
	}
	_BinaryTreeInOrder(root->_left, arr, pi);
	printf("%c ", root->_data);
	_BinaryTreeInOrder(root->_right, arr, pi);
}

void BinaryTreeInOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
		return;
	int treeSize = BinaryTreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*treeSize);
	int i = 0;
	_BinaryTreeInOrder(root, arr, &i);

}

void _BinaryTreePostOrder(BTNode* root, int* arr, int* pi)
{
	if (root == NULL)
		return;
	_BinaryTreePostOrder(root->_left, arr, pi);
	_BinaryTreePostOrder(root->_right, arr, pi);
	printf("%c ", root->_data);
}

void BinaryTreePostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
	{
		return;
	}
	int treeSize = BinaryTreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*treeSize);
	int i = 0;
	_BinaryTreePostOrder(root, arr, &i);
	
}

void BinaryTreeLevelOrder(BTNode* root)//层序遍历
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			printf("%c ", front->_data);
			if (front->_left)
			{
				QueuePush(&q, front->_left);
			}
			if (front->_right)
			{
				QueuePush(&q, front->_right);
			}
		}
	}
	printf("\n");
}

void BinaryTreePrevOrderNonR(BTNode* root)//前序遍历的非递归
{
	Stack st;
	StackInit(&st,10);
	BTNode* cur = root;
	while (cur || StackEmpty(&st) != 0)
	{
		//开始访问一棵树
		//1.先访问树的左路节点
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		StackPop(&st);
		//2.访问左路节点的右子树
		cur = top->_right;		
	}
	printf("\n");
}

void BinaryTreeInOrderNonR(BTNode* root)//中序遍历的非递归
{
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	//1.压左路节点
	while (cur || StackEmpty(&st) != 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//2.取出左路节点，并访问左路节点的右子树
		BTNode* top = StackTop(&st);
		printf("%c ", top->_data);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}

void BinaryTreePostOrderNonR(BTNode* root)//后序遍历的非递归
{
	Stack st;
	StackInit(&st,10);
	BTNode* cur = root;
	BTNode* prev = NULL;
	while (cur || StackEmpty(&st) != 0)
	{
		//1.把压左路节点入栈
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		//右树访问过了，才能访问根节点
		if (top->_right == NULL || top->_right == prev)//判断右树是否已经访问过，如果不判断就会出现死循环
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		else
		{
			cur = top->_right;
		}
	 }
	printf("\n");
}