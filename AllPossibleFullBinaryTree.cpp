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
    map<int,vector<TreeNode*>> m;
    vector<TreeNode*> allPossibleFBT(int N) {
        if(m.find(N) == m.end()) {
            vector<TreeNode*> res;
            if(N==1) res.push_back(new TreeNode(0));
            else if(N%2 == 1) {
                for(int x = 0; x<N; x++) {
                    int y = N-x-1;
                    for(auto l:allPossibleFBT(x)) {
                        for(auto r:allPossibleFBT(y)) {
                            TreeNode* node = NULL;
                            node = new TreeNode(0);
                            node->left = l;
                            node->right = r;
                            res.push_back(node);
                        }
                    }
                }
            }
            m.insert({N,res});
        }
        return m[N];
    }
};