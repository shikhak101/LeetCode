/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 0 - BOTH CHILDREN PENDING
// 1 - LEFT CHILD TRAVERSED
// 2 - BOTH CHILDREN TRAVERSED
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, int>> s;
        if(root == NULL) return NULL;
        s.push({root,0});
        TreeNode* LCA = NULL;
        bool onefound = false;
        while(!s.empty()) {
            TreeNode* curr = s.top().first;
            int stat = s.top().second;
            TreeNode* child_node = NULL;
            if(stat == 2) {
                s.pop();
                if(LCA == curr && onefound == true) {
                    LCA = s.top().first;
                }
            }
            else{
                if(stat == 0) {
                    if(curr == p || curr == q) {
                        if(onefound == true) return LCA;
                        onefound = true;
                        LCA = curr;
                    }
                    child_node = curr->left;
                }
                else if(stat == 1) {
                    child_node = curr->right;
                }
                s.top().second++;
                if(child_node!=NULL) {
                    s.push({child_node,0});
                }
            }
        }
        return LCA;
    }
};