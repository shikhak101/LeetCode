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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int p = 0;
        int cmax = root->val;
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int l = q.front().second;
            q.pop();
            if(p<l) {
                cmax = curr->val;
                res.push_back(cmax);
                p=l;
            }
            else if(p==l) {
                if(cmax<curr->val){
                    res.pop_back();
                    res.push_back(curr->val);
                    cmax = curr->val;
                }
            }
            if(curr->left!=NULL) q.push({curr->left,l+1});
            if(curr->right!=NULL) q.push({curr->right,l+1});
        }
        return res;
    }
};