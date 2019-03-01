/*��Ŀ�����������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ������,
s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������*/


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