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
    bool output = false;
    int currsum=0;
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(root == NULL) return false;
        //if(currsum == sum) return true;
        calc(root,0,sum);
        return output;
    }
    bool calc(TreeNode *root,int currsum,int sum)
    {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && currsum+root->val == sum)
        {
            output = true;
            return true;
        }
        else
        {
            currsum += root->val;
            calc(root->left,currsum,sum);
            calc(root->right,currsum,sum);
        }
        return false;
    }
};