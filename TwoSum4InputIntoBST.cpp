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
    vector<int> s;
    bool findTarget(TreeNode* root, int k) {
        generateset(root);
        for(int i=0; i<s.size(); i++){
            int diff = k-s[i];
            if(find(s.begin(),s.end(),diff) != s.end() && diff!=s[i]) return true;
        }
        return false;
    }
    void generateset(TreeNode* root) {
        if(root == NULL) return;
        s.push_back(root->val);
        generateset(root->left);
        generateset(root->right);
    }
};