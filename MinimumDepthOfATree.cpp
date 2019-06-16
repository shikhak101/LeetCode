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
    int mindepth = 100000;
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        height(root,1);
        return mindepth;
    }
    void height(TreeNode* root, int ht)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            if(ht < mindepth)
                mindepth = ht;
        }
        if(root->left != NULL)
        {
            height(root->left, ht+1);
        }
        if(root->right != NULL)
        {
            height(root->right, ht+1);
        }
        return;
    }
};