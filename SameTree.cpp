class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p != NULL && q != NULL)
        {
            bool val1 = isSameTree(p->left,q->left);
            bool val2 = isSameTree(p->right,q->right);
            //cout<<p->val<<" "<<q->val<<"\n";
            if(val1 == true && val2 == true && p->val==q->val) return true;
        }
        if(p == q) return true;
        return false;
    }
};