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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)) return false;
        if(root1 == NULL && root2 == NULL) return true;
        return solution(root1,root2);
    }
    bool solution(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL && r2 == NULL) return true;
        if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)) return false;
        if(r1->val != r2->val) return false;        
        if(r1->val  == r2->val) {
            bool l = solution(r1->left,r2->left);
            bool r = solution(r1->right,r2->right);
            if(l == true && r == true) return true;
            else {
                bool l = solution(r1->left,r2->right);
                bool r = solution(r1->right,r2->left);
                if(l == true && r == true) return true;
                else return false;
            }
        }
        return false;
    }
};