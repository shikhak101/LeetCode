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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        queue<int> level;
        if(root==NULL) return res;
        q.push(root);
        level.push(0);
        int prev = 0;
        double sum = root->val;
        double nodes = 1;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            int l = level.front();
            level.pop();
            if(curr->left != NULL) {
                level.push(l+1);
                q.push(curr->left);
            }
            if(curr->right!=NULL) {
                q.push(curr->right);
                level.push(l+1);
            }
            if(prev != l) {
                double d = sum/nodes;
                cout<<d<<endl;
                res.push_back(d);
                sum = curr->val;
                nodes = 1;
            }
            else {
                sum += curr->val;
                nodes++;
            }
            prev = l;
        }
        if(nodes>0) {
            double d = sum/nodes;
            res.push_back(d);
        }
        return res;
    }
};