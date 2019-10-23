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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        map<TreeNode*, TreeNode*> parent;
        set<TreeNode*> ancestors;
        if(root==NULL) return root;
        q1.push(root);
        parent.insert({root,NULL});
        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* curr = q1.front();
            q1.pop();
            if(curr->left!=NULL) {
                q1.push(curr->left);
                parent.insert({curr->left,curr});
            }
            if(curr->right!=NULL) {
                q1.push(curr->right);
                parent.insert({curr->right,curr});
            }
        }
        while(p!=NULL) {
            ancestors.insert(p);
            p = parent[p];
        }
        while(ancestors.find(q)==ancestors.end()) {
            q = parent[q];
        }
        return q;
    }
};