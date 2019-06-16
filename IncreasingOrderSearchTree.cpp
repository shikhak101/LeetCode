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
    TreeNode* head = NULL;
    TreeNode* node = NULL;
    TreeNode* increasingBST(TreeNode* root) {
        solution(root);
        return head;
    }
    void solution(TreeNode* curr)
    {
        if(curr == NULL) return;
        
        if(curr->left!= NULL)
        {
            solution(curr->left);
        }
        
        if(head == NULL)
        {
            node = curr;
            head = node;
        }
        else
        {
            TreeNode* temp = new TreeNode(curr->val);
            node->right = temp;
            node = node->right;
        }
        if(curr->right!=NULL)
        {
            solution(curr->right);
        }
        return;
    }
};