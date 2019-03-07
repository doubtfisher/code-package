//ºóÐò±éÀú¶þ²æÊ÷

//cµÝ¹é

* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };

int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
	}
}

_postorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;
	_postorderTraversal(root->left, array, pIndex);
	_postorderTraversal(root->right, array, pIndex);
	array[*pIndex] = root->val;
	(*pIndex)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc((*returnSize)*sizeof(int));
	int index = 0;
	_postorderTraversal(root, array, &index);

	return array;
}



//c++·ÇµÝ¹é

* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* prev = NULL;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			TreeNode* top = st.top();
			if (top->right == NULL || top->right == prev)
			{
				v.push_back(top->val);
				st.pop();
				prev = top;
			}
			else
			{
				cur = top->right;
			}
		}
		return v;
	}
};