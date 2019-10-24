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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        solution(root);
        return sum;
    }
    int solution(TreeNode* root) {
        if(root == NULL) return 0;
        int val=solution(root->left);
        if(val!=0 && root->left->left == NULL && root->left->right == NULL) sum+=val;
        solution(root->right);
        return root->val;
    }
};