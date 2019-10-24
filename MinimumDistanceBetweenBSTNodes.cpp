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
    int mindiff = INT_MAX; int prevval = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        minDiffInBST(root->left);
        mindiff = min(mindiff,abs(prevval-root->val));
        prevval = root->val;
        minDiffInBST(root->right);
        return mindiff;
    }
};