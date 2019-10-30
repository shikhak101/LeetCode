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
    bool binarysearch(int mid, TreeNode* root, int d) {
        int low = 0;
        int high = pow(2,d)-1;
        int currmid;
        for(int i=0; i<d; i++) {
            currmid = low + (high-low)/2;
            if(currmid<mid) {
                root = root->right;
                low = currmid+1;
            }
            else {
                root = root->left;
                high = currmid-1;
            }
        }
        if(root == NULL) return false;
        return true;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* curr = root;
        int d = 0;
        while(curr->left!=NULL) {
            d++;
            curr = curr->left;
        }
        if(d == 0) {
            return 1;
        }
        int res = pow(2,d) - 1;
        int low = 0; 
        int high = pow(2,d) -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            bool exists = binarysearch(mid,root,d);
            if(exists == true) low = mid+1;
            else high = mid - 1;
        }
        return low+res;
    }
};