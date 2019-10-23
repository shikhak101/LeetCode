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
    string s = "";
    string tree2str(TreeNode* t) {
        if(t == NULL) return s;
        s += to_string(t->val);
        if(t->left == NULL && t->right==NULL) return s;
        if(t->left!=NULL)
            solution(t->left);
        else s+="()";
        if(t->right!=NULL)
            solution(t->right);
        return s;
    }
    void solution(TreeNode* t) {
        if(t == NULL) {
            s+= "()";
            return;
        }
        s+= "(" + to_string(t->val);
        if(t->left == NULL && t->right == NULL){
            s+=')';
            return;
        }
        solution(t->left);
        if(t->right!=NULL)
            solution(t->right);
        s+=')';
    }
};