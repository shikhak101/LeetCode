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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res(2,NULL);
        if(root == NULL){
            return res; 
        }
        else if(root->val<=V){
            res = splitBST(root->right,V);
            root->right = res[0];
            res[0] = root;
        }
        else{
            res = splitBST(root->left,V);
            root->left = res[1];
            res[1] = root;
        }
        return res;
    }
};