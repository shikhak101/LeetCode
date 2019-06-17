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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()>0)
        {
            int mid = nums.size()/2;
            TreeNode* root = new TreeNode(nums[mid]);
            //root->val = nums[mid];
            calc(root,0,mid-1,nums);
            calc(root,mid+1,nums.size()-1,nums);
            return root;
        }
        return NULL;
    }
    void calc(TreeNode* root,int low,int high,vector<int> nums)
    {
        if(low < high)
        {    
            int mid = (high+low)/2;
            //root->val = nums[mid];
            if(nums[mid]<root->val)
            {
                TreeNode* temp = new TreeNode(nums[mid]);
                root->left = temp;
                root = temp;
            }
            if(nums[mid]>root->val)
            {
                TreeNode* temp = new TreeNode(nums[mid]);
                root->right = temp;
                root = temp;
            }
            calc(root,low,mid-1,nums);
            calc(root,mid+1,high,nums);
        }
        else if (low == high)
        {
            if(nums[low]<root->val)
            {
                TreeNode* temp = new TreeNode(nums[low]);
                root->left = temp;
                root = temp;
            }
            if(nums[low]>root->val)
            {
                TreeNode* temp = new TreeNode(nums[low]);
                root->right = temp;
                root = temp;
            }
        }
    }
};