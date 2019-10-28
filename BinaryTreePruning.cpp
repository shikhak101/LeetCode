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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        solution(root);
        return root;
    }
    int solution(TreeNode* root) {
        if(root == NULL) return 0;
        int l = solution(root->left);
        int r = solution(root->right);
        if(l == 0) root->left = NULL;
        if(r == 0) root->right = NULL;
        if(root->val == 1 || l == 1 || r==1) return 1;
        return 0;
    }
};