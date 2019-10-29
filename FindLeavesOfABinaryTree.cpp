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
    vector<vector<int>> res; vector<int> temp; TreeNode* rootnode = NULL;
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root == NULL) return res;
        rootnode = root;
        solution(root, NULL, 0);
        temp.clear();
        temp.push_back(root->val);
        res.push_back(temp);
        return res;
    }
    void solution(TreeNode* root, TreeNode* prev, int l) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            temp.push_back(root->val);
            if(prev!=NULL) {
                if(l ==1) prev->left = NULL;
                else if(l == 2) prev->right = NULL;
            }
            return;
        }
        solution(root->left,root,1);
        solution(root->right,root,2);
        if(root == rootnode) {
            res.push_back(temp);
            temp.clear();
            solution(rootnode,NULL,0);
        }
    }
};