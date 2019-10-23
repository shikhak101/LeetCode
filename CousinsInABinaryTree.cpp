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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;
        if(root->val == x || root->val == y) return false;
        queue<TreeNode*> q;
        q.push(root);
        queue<int> level;
        level.push(0);
        TreeNode* xp = NULL;
        TreeNode* yp = NULL;
        int xl = 0; int yl = 0;  
        while(!q.empty() && (xp==NULL || yp==NULL)) {
            TreeNode* curr = q.front();
            int l = level.front();
            q.pop(); level.pop();
            if(curr->left != NULL) {
                q.push(curr->left);
                level.push(l+1);
                if(curr->left->val == x) {
                    xl = l+1; xp = curr;
                }
                else if(curr->left->val == y) {
                    yl = l+1; yp = curr;
                }
            }
            if(curr->right != NULL) {
                q.push(curr->right);
                level.push(l+1);
                if(curr->right->val == x) {
                    xl = l+1; xp = curr;
                }
                else if(curr->right->val == y) {
                    yl = l+1; yp = curr;
                }
            }
        }
        if(xp != yp && xl == yl) return true;
        return false;
    }
};