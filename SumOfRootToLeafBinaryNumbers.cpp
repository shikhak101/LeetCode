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
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;
        solution(root,"0");
        return sum;
    }
    int solution(TreeNode* root, string num) {
        if(root == NULL) return 0;
        num += to_string(root->val);
        solution(root->left,num);
        solution(root->right,num);
        if(root->left != NULL || root->right != NULL) return 0;
        int currsum = 0;
        int p=0;
        for(int i=num.length()-1; i>=0; i--) {
            int d;
            if(num[i] == '0') d = 0;
            else d = 1;
            currsum += pow(2,p) * d;
            p++;
        }
        sum += currsum;
        // cout<<currsum<<","<<sum<<endl;
        return 0;
    }
};