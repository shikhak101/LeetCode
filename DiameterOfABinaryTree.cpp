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
    int maxlen = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        solution(root);
        return maxlen-1;
    }
    int solution(TreeNode* node) {
        if(node == NULL) return 0;
        int left = solution(node->left);
        int right = solution(node->right);
        maxlen = max(maxlen, (left+right+1));
        return max(left,right)+1;
    }
};