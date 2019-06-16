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
    int maxdiff = 0;
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int ht  = height(root);
        if(maxdiff > 1) return false;
        return true;
    }
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left = height(root->left)+1;
        int right = height(root->right)+1;
        if(maxdiff < abs(left-right)) maxdiff = abs(left-right);
        if(left > right) return left;
        return right;
    }
};