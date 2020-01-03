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
    pair<int,int> backtrack(TreeNode* root, int in, int dec) {
        if(root->left!=NULL) {
            pair<int,int> pl = backtrack(root->left,1,1);
            if(root->left->val==root->val-1) dec = max(pl.second+1,dec);
            else if(root->left->val==root->val+1) in = max(pl.first+1,in);
        }
        if(root->right!=NULL) {
            pair<int,int> pr = backtrack(root->right,1,1);
            if(root->right->val==root->val-1) dec = max(pr.second+1,dec);
            else if(root->right->val==root->val+1) in = max(pr.first+1,in);
        }
        res = max(res,in+dec-1);
        pair<int,int> p = {in,dec};
        return p;
    }
    int longestConsecutive(TreeNode* root) {
        res = 1;
        if(root == NULL) return 0;
        backtrack(root,1,1);
        return res;
    }
};