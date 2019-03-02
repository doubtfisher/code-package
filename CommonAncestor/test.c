//题目：求两棵树的最近公共祖先

//时间复杂度为O(N)
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
typedef struct TreeNode* STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//栈顶
	int _capacity;

}Stack;


void StackInit(Stack* ps, int n)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*n);
	ps->_top = 0;
	ps->_capacity = n;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}

void StackPush(Stack* ps, STDataType x)//在栈顶入数据
{
	assert(ps);
	if (ps->_top == ps->_capacity)//容量检测
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;

}

void StackPop(Stack* ps)//在栈顶出数据
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}

STDataType StackTop(Stack* ps)//取出栈顶的数据
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)//返回数据个数
{
	assert(ps);
	return ps->_top;//top其实就是链表中的size

}

int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void  Find(Stack* st, struct TreeNode* root, struct TreeNode* p)
{
	if (root == NULL)
		return;
	struct TreeNode* cur = root;
	struct TreeNode* prev;
	while (cur != NULL || StackEmpty(st) != 0)
	{
		while (cur)//遍历左路节点
		{

			if (cur->val == p->val)//若是p就是cur，直接返回函数
			{
				StackPush(st, cur);
				return;
			}
			else//遍历左路节点，找p
			{
				StackPush(st, cur);
				cur = cur->left;
			}
		}
		//访问右路节点
		struct TreeNode* top = StackTop(st);

		if (top->right == NULL || top->right == prev)
		{
			prev = top;
			StackPop(st);
			//cur= NULL;
		}
		else
			cur = top->right;
	}
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	Stack st_p;
	Stack st_q;
	StackInit(&st_p, 10);
	StackInit(&st_q, 10);
	if (root == NULL)
		return NULL;

	//找p的路径
	Find(&st_p, root, p);

	//找q的那条路径
	Find(&st_q, root, q);
	int sz1 = StackSize(&st_p);
	int sz2 = StackSize(&st_q);
	int gap = abs(sz1 - sz2);
	if (sz1<sz2)
	{
		while (gap--)
		{
			StackPop(&st_q);
		}
	}
	else
	{
		while (gap--)
		{
			StackPop(&st_p);
		}
	}
	//同时pop
	if (sz1 == 0)
		return root;
	struct TreeNode* top;
	while (StackEmpty(&st_p) != 0 && StackEmpty(&st_q) != 0)
	{
		struct TreeNode* top1 = StackTop(&st_p);
		struct TreeNode* top2 = StackTop(&st_q);
		if (top1->val != top2->val)
		{
			StackPop(&st_p);
			StackPop(&st_q);
		}
		else
		{
			top = top1;
			break;
		}
	}

	return top;
}

//时间复杂度为O(N2)

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool FindNode(struct TreeNode* root, struct TreeNode* node)
{
	if (root == NULL)
		return false;

	if (root == node)
		return true;

	return   FindNode(root->left, node)
		|| FindNode(root->right, node);
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return NULL;

	if (root == p || root == q)
		return root;

	//确定p和q的位置
	bool pLeft, pRight, qLeft, qRight;
	if (FindNode(root->left, p))
	{
		pLeft = true;
		pRight = false;
	}
	else
	{
		pLeft = false;
		pRight = true;
	}

	if (FindNode(root->left, q))
	{
		qLeft = true;
		qRight = false;
	}
	else
	{
		qLeft = false;
		qRight = true;
	}
	//p、q都在左子树
	if (pLeft&&qLeft)
	{
		return lowestCommonAncestor(root->left, p, q);
	}
	else if (pRight&&qRight)  //p、q都在右子树
	{
		return lowestCommonAncestor(root->right, p, q);
	}
	else//p、q在左右子树
	{
		return root;
	}
}