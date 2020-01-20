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
    TreeNode* backtrack(TreeNode* curr, int t) {
        if(curr == NULL) return NULL;
        curr->left = backtrack(curr->left,t);
        curr->right = backtrack(curr->right,t);
        if(curr->left == NULL && curr->right==NULL && curr->val==t){
            return NULL;
        }
        return curr;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return root;
        root = backtrack(root,target);
        return root;
    }
};