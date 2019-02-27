//题目描述：给定一个二叉树，判断它是否是高度平衡的二叉树。高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

//方法1：时间复杂度为O(N2)
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;	
};

int max_Depth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int left_depth = max_Depth(root->left);
	int right_depth = max_Depth(root->right);

	return left_depth>right_depth ? left_depth + 1 : right_depth + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;

	int left_depth = max_Depth(root->left);
	int right_depth = max_Depth(root->right);

	return abs(left_depth - right_depth)<2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}

//方法2：时间复杂度为O(N)

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

bool _isBalanced(struct TreeNode* root, int *pDepth)
{
	if (root == NULL)
	{
		*pDepth = 0;
		return true;
	}

	int leftDepth, rightDepth;
	if (_isBalanced(root->left, &leftDepth)
		&& _isBalanced(root->right, &rightDepth)
		&& abs(leftDepth - rightDepth)<2)
	{
		*pDepth = leftDepth>rightDepth ? leftDepth + 1 : rightDepth + 1;
		return true;
	}
	else
	{
		return false;
	}
}
bool isBalanced(struct TreeNode* root) {
	int depth = 0;
	return _isBalanced(root, &depth);
}