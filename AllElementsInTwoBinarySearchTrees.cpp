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
    void getres1(TreeNode* root1, vector<int>& res1) {
        if(root1==NULL) return;
        getres1(root1->left,res1);
        res1.push_back(root1->val);
        getres1(root1->right,res1);
    }
    void getres2(TreeNode* root2, vector<int>& res2) {
        if(root2==NULL) return;
        getres2(root2->left,res2);
        res2.push_back(root2->val);
        getres2(root2->right,res2);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        vector<int> res;
        getres1(root1,res1);
        getres2(root2,res2);
        int i = 0;
        int j = 0;
        while(i<res1.size() && j<res2.size()) {
            if(res1[i]<res2[j]) {
                res.push_back(res1[i]);
                i++;
            }
            else {
                res.push_back(res2[j]);
                j++;
            }
        }
        while(i<res1.size()) {
            res.push_back(res1[i]);
            i++;
        }
        while(j<res2.size()) {
            res.push_back(res2[j]);
            j++;
        }
        return res;
    }
};