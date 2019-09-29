/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> node;
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    void pushLeft(TreeNode* root) {
        while(root!=NULL) {
            node.push(root);
            root = root->left;
        }
    }
    /** @return the next smallest number */
    int next() {
        int val = node.top()->val;
        TreeNode* temp = node.top();
        node.pop();
        if(temp->right!=NULL) {
            pushLeft(temp->right);
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(node.size()>0) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */