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
    int findTilt(TreeNode* root) {
        solution(root);
        return sum;
    }
    int solution(TreeNode* root) {
        if(root == NULL) return 0;
        int l = solution(root->left);
        root->val += l;
        int r = solution(root->right);
        root->val += r;
        sum += abs(l-r);
        // cout<<l<<","<<r<<endl;
        return root->val;
    }
};