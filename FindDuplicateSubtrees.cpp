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
    map<string, int> tree;
    vector<TreeNode*> res;
    string helper(TreeNode* root){
        if(root == NULL) return "";
        string str = to_string(root->val)+","+helper(root->left)+","+helper(root->right);
        tree[str]++;
        if(tree[str]==2) res.push_back(root);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return res;
    }
};