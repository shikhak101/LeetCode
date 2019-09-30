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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<pair<int, TreeNode*>> v;
        if(root == NULL) return res;
        v.push_back(make_pair(0,root));
        int i=0;
        while(i<v.size()){
            if(v[i].second->left != NULL)
                v.push_back(make_pair(v[i].first+1,v[i].second->left));
            if(v[i].second->right != NULL)
                v.push_back(make_pair(v[i].first+1,v[i].second->right));
            i++;
        }
        int k = 0;
        i=0;
        while(i<v.size()) {
            vector<int> v1;
            while(i<v.size() && v[i].first == k){
                v1.push_back(v[i].second->val);
                i++;
            }
            k++;
            res.push_back(v1);
        }
        return res;
    }
};