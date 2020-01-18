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
    vector<TreeNode*> backtrack(int l, int h) {
        vector<TreeNode*> res;
        if(l>h) {
            res.push_back(NULL);
            return res;
        }
        for(int i=l; i<=h; i++) {
            vector<TreeNode*> left = backtrack(l,i-1);
            vector<TreeNode*> right = backtrack(i+1,h);
            for(auto x:left) {
                for(auto y:right) {
                    TreeNode* curr = NULL;
                    curr = new TreeNode(i);
                    curr->left = x;
                    curr->right = y;
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0) return res;
        return backtrack(1,n);
    }
};