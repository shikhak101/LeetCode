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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        return solution(preorder,INT_MIN,INT_MAX);
    }
    int i=0;
    TreeNode* solution(vector<int>& preorder, int cmin,int cmax) {
        if(i>=preorder.size()) return NULL;
        int val = preorder[i];
        if(val<cmin || val>cmax) return NULL;
        i++;
        TreeNode* root = NULL;
        root = new TreeNode(val);
        root->left = solution(preorder,cmin,val);
        root->right = solution(preorder,val,cmax);
        return root;
    }
};