//¶þ²æÊ÷ÖÐÐò±éÀú

//cÓïÑÔµÝ¹é

* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + GetTreeSize(root->left) + GetTreeSize(root->right);
}

void  _inorder(struct TreeNode* root, int *arr, int *pi)
{
	if (root == NULL)
		return;

	_inorder(root->left, arr, pi);
	arr[*pi] = root->val;
	(*pi)++;
	_inorder(root->right, arr, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int *arr = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	_inorder(root, arr, &i);

	return arr;
}


//c++·ÇµÝ¹é

* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			TreeNode* top = st.top();
			v.push_back(top->val);
			st.pop();
			cur = top->right;
		}

		return v;
	}
};