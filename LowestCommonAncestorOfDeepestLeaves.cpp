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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return NULL;
        unordered_map<TreeNode*,TreeNode*> m;
        set<TreeNode*> st;
        queue<pair<pair<TreeNode*,TreeNode*>,int>> q;
        vector<TreeNode*> v;
        q.push({{root,NULL},0});
        m.insert({root,NULL});
        int prev = -1;
        while(!q.empty()) {
            TreeNode* curr = q.front().first.first;
            TreeNode* p = q.front().first.second;
            int l = q.front().second;
            m.insert({curr,p});
            q.pop();
            if(curr->left==NULL && curr->right == NULL) {
                if(prev<l) {
                    prev=l;
                    v.clear();
                    v.push_back(curr);
                }
                else if(prev==l) v.push_back(curr);
            }
            if(curr->left!=NULL) q.push({{curr->left,curr},l+1});
            if(curr->right!=NULL) q.push({{curr->right,curr},l+1});
        }
        for(auto x:v) cout<<x->val<<endl;
        TreeNode* res = NULL;
        if(v.size()==1) {
            return v[0];
        }
        TreeNode* t = v[0];
        while(t!=NULL) {
            st.insert(t);
            t = m[t];
        }
        for(int i=1; i<v.size(); i++) {
            TreeNode* curr = v[i];
            while(st.find(curr)==st.end()) {
                curr = m[curr];
            }
            if(i==v.size()-1) return curr;
            st.clear();
            while(curr!=NULL) {
                st.insert(curr);
                curr = m[curr];
            }
        }
        
        return res;
    }
};