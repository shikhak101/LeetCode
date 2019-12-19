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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        map<TreeNode*,pair<int,int>> m;
        queue<TreeNode*> q;
        q.push(root);
        m.insert({root,{0,1}});
        int prev = -1;
        int end = 1;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            auto p = m[node];
            int l = p.first;
            int pos = p.second;
            if(prev != l){
                int t = end-pos+1;
                res = max(res,t);
                prev = l;
            }
            if(node->left!=NULL) {
                q.push(node->left);
                m.insert({node->left,{l+1,(2*pos)%INT_MAX}});
                end = (2*pos)%INT_MAX;
            }
            if(node->right!=NULL) {
                q.push(node->right);
                m.insert({node->right,{l+1,(2*pos+1)%INT_MAX}});
                end = (2*pos+1)%INT_MAX;
            }
        }
        return res;
    }
};