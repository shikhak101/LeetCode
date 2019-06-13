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
    vector<string> str;
    vector<int> s;
    void solution(TreeNode* node, TreeNode* root)
    {
        if(node == NULL) return;
        s.push_back(node->val);
        if(node->left == NULL && node->right == NULL)
        {
            string temp = "";
            for(int i=0; i<s.size(); i++)
            {
                if(i != 0) temp += "->";
                temp += to_string(s[i]);
            }
            str.push_back(temp);
            s.pop_back();
            return;
        }
        if(node->left != NULL)
        {
            // cout<<node->val<<"----L"<<node->left->val<<"\n";
            solution(node->left,root);
        }
        if(node->right != NULL)
        {
            // cout<<node->val<<"----"<<node->right->val<<"\n";
            solution(node->right,root);
        }
        s.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return str;
        solution(root,root);
        return str;
    }
};