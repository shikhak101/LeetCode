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
    void func(TreeNode* curr, int& sum){
        if(curr == NULL) return;
        func(curr->right,sum);
        sum += curr->val;
        curr->val = sum;
        func(curr->left, sum);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return root;
        int sum =0;
        func(root,sum);
        return root;
    }
};