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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        TreeNode* root = NULL;
        root = solution(root,0,nums.size()-1,nums);
        return root;
    }
    TreeNode* solution(TreeNode* node, int start, int end, vector<int>& nums) {
        if(start == end) {
            TreeNode* newnode = NULL;
            newnode = new TreeNode(nums[start]);
            return newnode;
        }
        if(start>end){ return NULL; }
        int currmax = INT_MIN;
        int idx = 0;
        for(int i = start; i<=end; i++){
            if(currmax<nums[i]) {
                currmax = nums[i];
                idx = i;
            }
        }
        node = new TreeNode(currmax);
        node->left = solution(node,start,idx-1,nums);
        node->right = solution(node,idx+1,end, nums);
        return node;
    }
};