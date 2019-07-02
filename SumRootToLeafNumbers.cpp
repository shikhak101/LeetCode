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
    int total = 0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return total;
        solution(root,root->val);
        return total;
    }
    void solution(TreeNode* curr, int currval)
    {
        if(curr == NULL) return;
        if(curr->left == NULL && curr->right == NULL)
            total += currval;
            
        if(curr->left != NULL)
        {
            solution(curr->left, (currval*10) + curr->left->val);
        }
        if(curr->right != NULL)
        {
            solution(curr->right, (currval*10) +curr->right->val);
        }
        return;
    }
};