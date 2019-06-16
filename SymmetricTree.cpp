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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || root->left==root->right) return true;
        if(root->left!=NULL && root->right!=NULL && root->left->val == root->right->val)
        {
            return check(root->left,root->right);
        }
        else return false;
    }
    bool check(TreeNode* node1, TreeNode* node2)
    {
        if(node1!=NULL && node2!=NULL)
        {
            bool val1 = check(node1->left,node2->right);
            bool val2 = check(node1->right,node2->left);
            if(val1 == true && val2 == true && node1->val==node2->val) return true;
        }
        if(node1==node2) return true;
        return false;
    }
};