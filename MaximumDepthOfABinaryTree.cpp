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
    int maxDepth(TreeNode* root) {
        int maxdep = 0;
        if(root == NULL) return 0;
        //if(root->left ==NULL && root->right == NULL) return 1;
        if(root != NULL)
        {
            int maxdep1 = maxDepth(root->left) + 1;
            int maxdep2 = maxDepth(root->right) + 1;
            if(maxdep1>maxdep2) maxdep = maxdep1;
            else maxdep = maxdep2;
        }
        return maxdep;
    }
};