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
    TreeNode* node = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solution(root,p,q);
        return node;
    }
    bool solution(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        
        if( root == NULL) return false;
        bool l = solution(root->left,p,q);
        bool r = solution(root->right,p,q);
        if(root == p || root==q) {
            if((l == true || r==true) && node == NULL) {
                node = root;
            }
            return true;
        }
        if(l == true && r==true && node == NULL) {
            node = root;
            return true;
        }
        if(l == true || r == true) return true;
        return false;
    }
};