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
    map<int,int> res;
    vector<int> ret;
    int mv = INT_MIN;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == NULL) return ret;
        int val = helper(root);
        if(res.find(val) == res.end()) res.insert({val,1});
        else res[val]++;
        mv = max(mv,res[val]);
        for(auto x:res) {
            if(x.second == mv) ret.push_back(x.first);
        }
        return ret;
    }
    int helper(TreeNode* root) {
        int l=0,r=0;
        if(root->left!=NULL) {
            l = helper(root->left);
            if(res.find(l) == res.end())
                res.insert({l,1});
            else
                res[l]++;
            mv = max(mv,res[l]);
        }
        if(root->right!=NULL){
            r = helper(root->right);
            if(res.find(r) == res.end())
                res.insert({r,1});
            else 
                res[r]++;
            mv = max(mv,res[r]);
        }
        return l+r+root->val;
    }
};