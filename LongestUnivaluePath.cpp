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
    int maxval = 0;
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        solution(root);
        return maxval;
    }
    int solution(TreeNode* root) {
        if(root== NULL) return 0;
        int l = solution(root->left);
        int r = solution(root->right);
        int lans = 0, rans = 0;
        if(root->left!=NULL && root->left->val == root->val) {
            lans += l+1;
        }
        if(root->right!=NULL && root->right->val == root->val) {
            rans += r+1;
        }
        maxval = max(maxval , lans+rans);
        
        return max(lans,rans);
    }
};