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
    int res;
    int count(TreeNode* curr) {
        if(curr == NULL) return 1;
        int l = count(curr->left);
        int r = count(curr->right);
        if((curr->left!=NULL && curr->left->val!=curr->val) || (curr->right!=NULL && curr->right->val!=curr->val)) return 0;
        if(l==r && l==1) {
            res++;
            return 1;
        }
        return 0;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
        res = 0;
        count(root);
        return res;
    }
};