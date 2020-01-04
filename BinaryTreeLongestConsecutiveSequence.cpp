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
    int backtrack(TreeNode* node, int seq){
        if(node->left!=NULL){
            int n = backtrack(node->left,1);
            if(node->val+1 == node->left->val) seq = max(seq,n+1);
        }
        if(node->right!=NULL){
            int n = backtrack(node->right,1);
            if(node->val+1 == node->right->val) seq = max(seq,n+1);
        }
        res = max(res,seq);
        return seq;
    }
    int longestConsecutive(TreeNode* root) {
        if(root==NULL) return 0;
        res = 0;
        backtrack(root,1);
        return res;
    }
};