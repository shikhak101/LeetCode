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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        int res = 0;
        q.push({root,0});
        int maxlevel = 0;
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level == maxlevel) {
                res += curr->val;
            }
            else if(level>maxlevel) {
                maxlevel = level;
                res = curr->val;
            }
            if(curr->left!=NULL){
                q.push({curr->left,level+1});
            }
            if(curr->right!=NULL) {
                q.push({curr->right,level+1});
            }
        }
        return res;
    }
};