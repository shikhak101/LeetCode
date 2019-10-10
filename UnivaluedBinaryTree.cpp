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
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        int val = root->val;
         return solution(root,val);
    }
    bool solution(TreeNode* root, int val) {
        if(root == NULL) return true;
        if(root->val != val) return false;
        bool l = solution(root->left,val);
        bool r = solution(root->right, val);
        if(l == true && r == true) return true;
        return false;
    }
};