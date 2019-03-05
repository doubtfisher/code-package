
//cÓïÑÔµÝ¹é
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return GetTreeSize(root->left)
			+ GetTreeSize(root->right) + 1;
	}
}
void _preorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;
	array[*pIndex] = root->val;
	(*pIndex)++;
	_preorderTraversal(root->left, array, pIndex);
	_preorderTraversal(root->right, array, pIndex);

}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc((*returnSize)*sizeof(int));
	int index = 0;
	_preorderTraversal(root, array, &index);

	return array;
}


//c++·ÇµÝ¹é
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		TreeNode* cur = root;
		stack<TreeNode*> st;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				v.push_back(cur->val);
				cur = cur->left;
			}
			TreeNode* top = st.top();
			st.pop();
			cur = top->right;
		}
		return v;
	}
};