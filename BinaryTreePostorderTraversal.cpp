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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* t = st.top();
            st.pop();
            res.insert(res.begin(),t->val);
            if(t->left!=NULL) st.push(t->left);
            if(t->right!=NULL) st.push(t->right);
        }
        
        return res;
    }
};