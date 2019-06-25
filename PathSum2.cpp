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
    vector<vector<int>> p;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if( root == NULL) return p;
        vector<int> q;
        solution(root, sum, root->val, q);
        return p;
    }
    void solution(TreeNode* root, int sum, int currsum, vector<int> q)
    {
        if(root == NULL) return;
        if(sum == currsum && root->left == NULL && root->right == NULL)
        {
            // cout<<"\n"<<currsum;
            q.push_back(root->val);
            p.push_back(q);
        }
        q.push_back(root->val);
        // cout<<root->val<<"-";
        if(root->left!=NULL)solution(root->left,sum, currsum+root->left->val, q);
        if(root->right!=NULL)solution(root->right, sum, currsum+root->right->val, q);
        return;
    }
};