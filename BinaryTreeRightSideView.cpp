/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if(root == NULL) return v;
        TreeNode* curr = root;
        TreeNode* rightMost = root;
        q.push(root);
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            if(curr == rightMost )
            {
                v.push_back(curr->val);
                rightMost = q.back();
            }
        }
        return v;
    }
};