//题目：要求采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串，空节点则用一对空括号 "()" 表示。
//而且需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。


//代码实现：

struct TreeNode {
    int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

char valstr[10];
char* _tree2str(struct TreeNode* t, char *str)
{
	if (t == NULL)
		return;

	//构建根
	sprintf(valstr, "%d", t->val);
	strcat(str, valstr);

	//构建左子树
	if (t->left == NULL)
	{
		if (t->right == NULL)
		{
			return;
		}
		else
		{
			strcat(str, "()");
		}
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}

	//构建右子树
	if (t->right == NULL)
		return;
	else
		strcat(str, "(");
	_tree2str(t->right, str);
	strcat(str, ")");

}

char str[100000];//注意这里必须置成全局变量，如果放在函数内部的话，一出作用域就会销毁
char* tree2str(struct TreeNode* t) {
	str[0] = '\0';//必须初始化第一个位置
	_tree2str(t, str);

	return str;
}