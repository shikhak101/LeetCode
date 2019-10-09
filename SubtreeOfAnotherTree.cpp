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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL && t==NULL) return true;
        return solution1(s,t);
    }
    bool solution1(TreeNode* s, TreeNode* t) {
        if(s!=NULL) {
            if(solution(s,t) == true || solution1(s->left,t) == true || solution1(s->right,t) == true) return true;
        }
        return false;
    }
    bool solution(TreeNode* s, TreeNode* t) {
        if(s==NULL && t==NULL) return true;
        if(s==NULL || t==NULL) return false;
        if(s->val == t->val) {
            bool l = solution(s->left, t->left);
            bool r = solution(s->right , t->right);
            if(l==true && r == true) return true;
        }
        return false;
    } 
};