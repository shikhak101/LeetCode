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
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        
        solution1(root,sum,0);
        return count;
    }
    void solution1(TreeNode* root, int sum, int csum) {
        if(root== NULL) return;
        solution(root,sum,csum);
        solution1(root->left,sum,0);
        solution1(root->right,sum,0);
    }
    void solution(TreeNode* root, int sum, int currsum) {
        if(root == NULL) return;
        currsum += root->val;
        if(currsum == sum) ++count;
        solution(root->left,sum,currsum);
        solution(root->right, sum, currsum);
    }
};
