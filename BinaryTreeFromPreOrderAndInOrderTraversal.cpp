/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <set>
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        std::vector<int>::iterator i = std::find(inorder.begin(), inorder.end(), root->val);
        vector<int> newpreorder1;
        vector<int> newinorder1;
        vector<int> newpreorder2;
        vector<int> newinorder2;
        for(int a = 0; a<(i- inorder.begin()); a++)
        {
            newpreorder1.push_back(preorder[a+1]);
            newinorder1.push_back(inorder[a]);
        }
        for(int b = i-inorder.begin()+1; b<inorder.size(); b++)
        {
            newpreorder2.push_back(preorder[b]);
            newinorder2.push_back(inorder[b]);
        }
      
        if(newpreorder1.size()>0 || newpreorder2.size()>0){
            root->left = buildTree(newpreorder1,newinorder1);
            root->right = buildTree(newpreorder2,newinorder2);
        }
        return root;
    }
};