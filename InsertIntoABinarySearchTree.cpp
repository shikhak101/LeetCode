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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        if(curr == NULL) root = new TreeNode(val);
        while(curr!=NULL) {
            if(curr->val < val){
                if(curr->right!=NULL) curr = curr->right;
                else {
                    TreeNode* temp = NULL;
                    temp = new TreeNode(val);
                    curr->right = temp;
                    break;
                }
            }
            else {
                if(curr->left!=NULL) curr = curr->left;
                else {
                    TreeNode* temp = NULL;
                    temp = new TreeNode(val);
                    curr->left = temp;
                    break;
                }
            }
        }
        return root;
    }
};