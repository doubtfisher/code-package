//要求：使用前序遍历和中序遍历构造二叉树

* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };

struct TreeNode* _buildTree(int* preorder, int * pindex, int *inorder, int begin, int end)
{
	if (begin>end)
		return NULL;
	//构建根
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[*pindex];
	//构建左子树
	int rootindex = begin;
	for (rootindex; rootindex <= end; rootindex++)
	{
		if (inorder[rootindex] == root->val)
		{
			break;
		}
	}
	(*pindex)++;
	root->left = _buildTree(preorder, pindex, inorder, begin, rootindex - 1);

	//构建右子树
	root->right = _buildTree(preorder, pindex, inorder, rootindex + 1, end);

	return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int index = 0;
	return _buildTree(preorder, &index, inorder, 0, inorderSize - 1);
}


//使用中序遍历、后序遍历构造二叉树

* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };

struct TreeNode* _buildTree(int* postorder, int* pindex, int* inorder, int begin, int end)
{
	if (begin>end)
		return NULL;

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = postorder[*pindex];

	int rootindex = begin;
	for (rootindex; rootindex <= end; rootindex++)
	{
		if (inorder[rootindex] == root->val)
		{
			break;
		}
	}
	(*pindex)--;
	root->right = _buildTree(postorder, pindex, inorder, rootindex + 1, end);

	root->left = _buildTree(postorder, pindex, inorder, begin, rootindex - 1);

	return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	int index = postorderSize - 1;
	return _buildTree(postorder, &index, inorder, 0, inorderSize - 1);
}
