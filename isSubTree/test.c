/*题目：给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树,
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。*/


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL&&t == NULL)
		return true;

	if (s == NULL || t == NULL)
		return false;

	return s->val == t->val
		&&isSameTree(s->left, t->left)
		&& isSameTree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;

	if (isSameTree(s, t))
		return true;

	if (isSubtree(s->left, t))
		return true;

	if (isSubtree(s->right, t))
		return true;

	return false;
}