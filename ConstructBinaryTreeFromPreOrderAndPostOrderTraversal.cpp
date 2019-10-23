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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return solution(pre,post,0,0,pre.size());
    }
    TreeNode* solution(vector<int>& pre, vector<int>& post, int s, int e, int N) {
        if(N==0) return NULL;
        TreeNode* root = NULL;
        root = new TreeNode(pre[s]);
        if(N == 1) return root;
        int L = 0;
        for(int i=1; i<N; i++) {
            if(pre[s+1] == post[e+i-1]) L = i;
        }
        root->left = solution(pre,post,s+1,e,L);
        root->right = solution(pre,post,s+L+1,e+L,N-L-1);
        return root;
    }
};