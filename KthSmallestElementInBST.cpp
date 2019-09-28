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
    vector<int> v;
    void sortedarr(TreeNode* root) {
        if(root == NULL) return;
        sortedarr(root->left);
        v.push_back(root->val);
        sortedarr(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        sortedarr(root);
        return v[k-1];
    }
};