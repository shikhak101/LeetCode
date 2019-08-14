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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        left = invertTree(root->left);
        right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};