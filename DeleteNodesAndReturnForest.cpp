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
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL) return res;
        res.push_back(root);
        queue<TreeNode*> q;
        q.push(root);
        queue<TreeNode*> parent;
        parent.push(NULL);
        queue<int> child;
        child.push(-1);
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            TreeNode* par = parent.front();
            parent.pop();
            int c = child.front();
            child.pop();
            if(t!=NULL) {
                q.push(t->left);
                parent.push(t); child.push(0);
                q.push(t->right);
                parent.push(t); child.push(1);
                if(find(to_delete.begin(), to_delete.end(), t->val) != to_delete.end()) {
                    if(c == -1) {
                        res.pop_back();
                    }
                    else {
                        if(c == 0) par->left = NULL;
                        else if(c==1) par->right = NULL;
                    }
                    t->val = -1;
                }
                else if(par != NULL && par->val == -1) {
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};