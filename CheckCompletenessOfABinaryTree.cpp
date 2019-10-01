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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return true;
        int fn = 0;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(fn == 1 && (node->left!=NULL || node->right!=NULL)){
                return false;
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
            else fn = 1;
            if(node->right!=NULL && fn == 0){
                q.push(node->right);
            }
            else if(node->right!=NULL && fn == 1)
                return false;
            else fn = 1;
        }
        return true;
    }
};