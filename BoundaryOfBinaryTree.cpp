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
    vector<int> res;
    void helperleft(TreeNode* node){
        if(node == NULL || (node->left==NULL && node->right==NULL)) return;
        res.push_back(node->val);
        if(node->left == NULL) helperleft(node->right);
        else helperleft(node->left);
    }
    void helperright(TreeNode* node){
        if(node == NULL || (node->left==NULL && node->right==NULL)) return;
        if(node->right == NULL) helperright(node->left);
        else helperright(node->right);
        res.push_back(node->val);
    }
    void helperleaf(TreeNode* node){
        if(node == NULL) return;
        if(node->left==NULL && node->right==NULL)
            res.push_back(node->val);
        helperleaf(node->left);
        helperleaf(node->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==NULL) return res;
        res.push_back(root->val);
        if(root->left!=NULL)
            helperleft(root->left);
        if(root->left!=NULL || root->right!=NULL)
            helperleaf(root);
        if(root->right!=NULL)
            helperright(root->right);
        return res;
    }
};