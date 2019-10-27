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
    vector<int> res;
    int maxcount = 1;
    int count = 0;
    vector<int> findMode(TreeNode* root) {
        if(root==NULL) return res;
        count = 0;
        solution(root,root->val);
        if(maxcount == count) {
            res.push_back(root->val);
        }
        else if(maxcount<count) {
            res.clear();
            maxcount = count;
            res.push_back(root->val);
        }
        findMode(root->left);
        findMode(root->right);
        return res;
    }
    void solution(TreeNode* root, int val) {
        if(root == NULL) return;
        if(root->val == val) {
            count++;
            solution(root->left,val);
            solution(root->right,val);
        }
        else if(root->val < val) {
            solution(root->right,val);
        }
        else solution(root->left,val);
    }
};