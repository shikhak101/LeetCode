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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            TreeNode* parent = q.front().second;
            q.pop();
            if(curr->val == key) {
                if(curr->left==NULL && curr->right==NULL) {
                    if(parent==NULL) return NULL;
                    if(parent->left==curr) parent->left = NULL;
                    else if(parent->right==curr) parent->right = NULL;
                }
                else if(curr->left==NULL){
                    if(parent==NULL) return curr->right;
                    if(parent->left==curr) parent->left = curr->right;
                    else if(parent->right==curr) parent->right = curr->right;
                }
                else if(curr->right==NULL){
                    if(parent==NULL) return curr->left;
                    if(parent->left==curr) parent->left = curr->left;
                    else if(parent->right==curr) parent->right = curr->left;
                }
                else {
                    TreeNode* l = curr->left;
                    TreeNode* r = curr->right;
                    TreeNode* rr = curr->left->right;
                    l->right = r;
                    while(r->left!=NULL) r = r->left;
                    r->left = rr;
                    if(parent==NULL){
                        root = l;
                    }
                    else if(parent->left==curr){
                        parent->left = l;
                    }
                    else if(parent->right==curr){
                        parent->right = l;
                    }
                }
                return root;
            }
            if(curr->left!=NULL) {
                q.push({curr->left,curr});
            }
            if(curr->right!= NULL) {
                q.push({curr->right,curr});
            }
        }
        return root;
    }
};