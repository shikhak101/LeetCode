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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        bool alternate = true;
        vector<int> temp;
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            temp.push_back(curr->val);
            if(alternate == true) {
                if(curr->left!=NULL) st2.push(curr->left);
                if(curr->right!=NULL) st2.push(curr->right);
            }
            else {
                if(curr->right!=NULL) st2.push(curr->right);
                if(curr->left!=NULL) st2.push(curr->left);
            }
            if(st1.empty()) {
                res.push_back(temp);
                temp.clear();
                stack<TreeNode*> t = st1;
                st1 = st2;
                st2 = t;
                alternate = !alternate;
            }
        }
        return res;
    }
};