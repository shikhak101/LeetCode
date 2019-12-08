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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root == NULL) return root;
        map<TreeNode*, TreeNode*> parent;
        q.push({root,1});
        parent.insert({root,NULL});
        int maxl = 1;
        vector<TreeNode*> deepest;
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l>maxl) {
                maxl = l;
                deepest.clear();
                deepest.push_back(curr);
            }
            else if(l == maxl) {
                deepest.push_back(curr);
            }
            if(curr->left!=NULL) {
                q.push({curr->left,l+1});
                parent.insert({curr->left,curr});
            }
            if(curr->right!=NULL) {
                q.push({curr->right,l+1});
                parent.insert({curr->right,curr});
            }
        }
        map<TreeNode*,int> m;
        TreeNode* curr = deepest[0];
        m.insert({curr,0});
        int k = 1;
        int currlevel = 0;
        TreeNode* res = curr;
        while(curr!=NULL) {
            m.insert({parent[curr],k++});
            curr = parent[curr];
        }
        for(int i=1; i<deepest.size(); i++) {
            TreeNode* c = deepest[i];
            while(c!=NULL) {
                if(m.find(parent[c])!=m.end() && m[parent[c]]>=currlevel) {
                    currlevel = m[parent[c]];
                    res = parent[c];
                    break;
                }
                c = parent[c];
            }
        }
        return res;
    }
};