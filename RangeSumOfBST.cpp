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
    int sum =0;
    void findSum(TreeNode* curr, int low, int high) {
        if(curr==NULL) return ;
        if(curr->val >= low && curr->val <= high) {
            sum += curr->val;
        }
        findSum(curr->left,low,high);
        findSum(curr->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        findSum(root,L,R);
        return sum;
    }
};