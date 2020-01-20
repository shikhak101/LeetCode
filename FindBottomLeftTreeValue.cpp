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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int res = 0;
        int p = -1;
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l!=p) {
                p=l;
                res = curr->val;
            }
            if(curr->left!=NULL) {
                q.push({curr->left,l+1});
            }
            if(curr->right!=NULL) {
                q.push({curr->right,l+1});
            }
        }
        return res;
    }
};