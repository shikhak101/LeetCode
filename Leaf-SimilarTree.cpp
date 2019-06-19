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
    vector<int> leafseq;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafseq1, leafseq2;
        leafseq1 = solution(root1);
        leafseq.clear();
        leafseq2 = solution(root2);
        if( leafseq1.size() != leafseq2.size()) return false;
        for(int i=0; i<leafseq1.size(); i++)
        {
            if(leafseq1[i] != leafseq2[i]) return false;
        }
        return true;
    }
    vector<int> solution(TreeNode* node)
    {
        if(node == NULL) return leafseq;
        if(node->left == NULL && node->right == NULL)
        {
            leafseq.push_back(node->val);
        }
        if(node->left != NULL)
        {
            solution(node->left);
        }
        if(node->right != NULL)
        {
            solution(node->right);
        }
        return leafseq;
    }
}; 