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
    TreeNode* curr = NULL;
    void flatten(TreeNode* root) {
        if(root)
	{
		flatten(root->right);
		flatten(root->left);
		if(root->left)
		{
			TreeNode* endLeft = root->left;
			while(endLeft->right) endLeft = endLeft->right;
			endLeft->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
	}
    }
};