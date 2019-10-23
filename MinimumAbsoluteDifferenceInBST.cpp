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
    int res = INT_MAX; int pval = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return 0;
        return solution(root);
    }
    int solution(TreeNode* root) {
        if(root == NULL) return res;
        solution(root->left);
        res = min(res,abs(pval-root->val));
        pval = root->val;
        solution(root->right);
        return res;
    }
};