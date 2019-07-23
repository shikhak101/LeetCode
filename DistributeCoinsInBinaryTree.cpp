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
    int tot_moves = 0;
    int distributeCoins(TreeNode* root) {
        solution(root);
        return tot_moves;
    }
    int solution(TreeNode* root) {
        if(root == NULL) return 0;
        int l = solution(root->left);
        int r = solution(root->right);
        tot_moves += abs(l) + abs(r);
        return l+r+root->val -1;
    }
};