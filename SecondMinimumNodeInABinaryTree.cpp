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
    long long int val = LONG_MAX;
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL || root->left == NULL)  return -1;
        solution(root,root->val);
        int secondmin = val;
        if(val == LONG_MAX) return -1;
        return secondmin;
    }
    void solution(TreeNode* root, int minval) {
        if(root->left != NULL) {
            if(root->left->val == root->right->val) {
                solution(root->left,minval);
                solution(root->right,minval);
            }
            else if(minval<root->left->val && val > root->left->val) {
                val = root->left->val;
                solution(root->right,minval);
            }
            else if(minval<root->right->val && val > root->right->val) {
                val = root->right->val;
                solution(root->left,minval);
            }
            else return;
        }
    }
};