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
    int closestValue(TreeNode* root, double target) {
        stack<TreeNode*> st;
        long long int pred = LONG_MIN;
        while(root!=NULL || !st.empty()) {
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop();
            if(pred<=target && target<=root->val) {
                return abs(pred-target)<abs(target-root->val)?pred:root->val;
            }
            pred = root->val;
            root = root->right;
            
        }
        return pred;
    }
};