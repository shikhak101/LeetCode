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
    void makeTree(vector<int>& nums, TreeNode* node, int low, int high) {
        if(low <= high) {
            int mid = (low+high)/2;
            TreeNode* temp;
            temp = new TreeNode(nums[mid]);
            if(nums[mid] < node->val) {
                node->left = temp;
                temp = node->left;
            }
            else {
                node->right = temp;
                temp = node->right;
            }
            makeTree(nums,temp,low,mid-1);
            makeTree(nums,temp,mid+1,high);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        if(nums.size() == 0) return root;
        int mid = (nums.size()-1)/2;
        root = new TreeNode(nums[mid]); 
        int low = 0;
        int high = nums.size()-1;
        if(low < high) {
            makeTree(nums,root,low,mid-1);
            makeTree(nums,root,mid+1, high);
        }
        return root;
    }
};