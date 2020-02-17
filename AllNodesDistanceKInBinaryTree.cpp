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
    vector<int> res;
    unordered_map<TreeNode*,TreeNode*> m;
    set<TreeNode*> vis;
    void helper(TreeNode* node, int k){
        if(node==NULL) return;
        if(vis.find(node)!=vis.end()) return;
        if(k==0){
            res.push_back(node->val);
            return;
        }
        vis.insert(node);
        helper(node->left,k-1);
        helper(node->right,k-1);
        helper(m[node],k-1);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == NULL || target==NULL) return res;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        m.insert({root,NULL});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            TreeNode* p = q.front().second;
            q.pop();
            if(curr->left!=NULL){
                q.push({curr->left,curr});
                m.insert({curr->left,curr});
            }
            if(curr->right!=NULL){
                q.push({curr->right,curr});
                m.insert({curr->right,curr});
            }
        }
        helper(target,K);
        return res;
    }
};