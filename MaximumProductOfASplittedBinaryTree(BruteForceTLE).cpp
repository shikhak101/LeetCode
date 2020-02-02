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
    unsigned long helper(TreeNode* root, TreeNode* node, TreeNode* parent){
        unsigned long sum = 0;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            TreeNode* p = q.front().second;
            q.pop();
            if(p!= NULL && node == curr && parent == p) continue;
            sum+=curr->val;
            if(curr->left!=NULL){
                q.push({curr->left,curr});
            }
            if(curr->right!=NULL){
                q.push({curr->right,curr});
            }
        }
        return sum;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;
        unsigned long sum = 0;
        unsigned long res = 0;
        map<TreeNode*,vector<TreeNode*>> m;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            TreeNode* p = q.front().second;
            q.pop();
            if(p!=NULL)
                m[p].push_back(curr);
            sum+=curr->val;
            if(curr->left!=NULL){
                q.push({curr->left,curr});
            }
            if(curr->right!=NULL){
                q.push({curr->right,curr});
            }
        }
        for(auto x:m){
            TreeNode* parent = x.first;
            for(int i=0; i<x.second.size(); i++){
                TreeNode* node = x.second[i];
                unsigned long sum1 = (helper(root,node,parent));
                unsigned long sum2 = (sum-sum1);
                res = max(res,sum1*sum2);
            }
        }
        return res%1000000007;
    }
};