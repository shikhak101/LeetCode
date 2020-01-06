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
    TreeNode* par = NULL;
    bool b = false;
    TreeNode* findParent(TreeNode* curr, TreeNode* p, TreeNode* parent) {
        if(curr->val == p->val) { b = true; return par;}
        if(curr->left!=NULL){
            findParent(curr->left,p,curr);
            if(par!=NULL) return par;
            if(b==true){ par = curr; return par;}
        }
        if(curr->right!=NULL){
            findParent(curr->right,p,curr);
            if(par!=NULL) return par;
        }
        return par;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL || p==NULL) return NULL;
        TreeNode* closestP = root;
        TreeNode* closestC = p->right;
        closestP = findParent(root,p,NULL);
        while(closestC!=NULL && closestC->left!=NULL) {
            closestC = closestC->left;
        }
        if(root == p) return closestC;
        if(closestP==NULL && closestC == NULL) return NULL;
        if(closestP == NULL) return closestC;
        if(closestC == NULL) return closestP;
        if(closestP->val>closestC->val) return closestC;
        return closestP;
    }
};