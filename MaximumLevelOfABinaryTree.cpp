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
    int maxLevelSum(TreeNode* root) {
        long long int maxsum=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        int level = 0;
        while(!q.empty()) {
            int sum = 0;
            int size = q.size();
            ++level;
            while(size>0) {
                --size;
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left!=NULL) {
                    q.push(curr->left);
                }
                if(curr->right!=NULL) {
                    q.push(curr->right);
                }
            }
            if(maxsum<sum) {
                maxsum = sum;
                res = level;
            }
        }
        return res;
    }
};