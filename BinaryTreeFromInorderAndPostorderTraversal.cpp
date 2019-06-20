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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty()) return NULL;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        std::vector<int>::iterator i = std::find(inorder.begin(), inorder.end(), root->val);
        vector<int> newpostorder1;
        vector<int> newinorder1;
        vector<int> newpostorder2;
        vector<int> newinorder2;
        for(int a = 0; a<(i- inorder.begin()); a++)
        {
            newpostorder1.push_back(postorder[a]);
            newinorder1.push_back(inorder[a]);
        }
        for(int b = i-inorder.begin()+1; b<inorder.size(); b++)
        {
            newpostorder2.push_back(postorder[b-1]);
            newinorder2.push_back(inorder[b]);
        }
      
        if(newpostorder1.size()>0 || newpostorder2.size()>0){
            root->left = buildTree(newinorder1, newpostorder1);
            root->right = buildTree(newinorder2, newpostorder2);
        }
        return root;
    
    }
};