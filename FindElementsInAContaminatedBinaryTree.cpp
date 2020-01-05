/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    set<int> st;
    FindElements(TreeNode* root) {
        if(root==NULL) return;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int k = 0;
        unordered_map<int,int> m;
        m[1]++;
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int l = q.front().second;
            q.pop();
            if(m.find(l) == m.end()) break;
            if(curr!=NULL) {
                st.insert(k);
                q.push({curr->left,l+1});
                q.push({curr->right,l+1});
                if(curr->left!=NULL){m[l+1]++;}
                if(curr->right!=NULL){m[l+1]++;}
            }
            else {
                q.push({NULL,l+1});
                q.push({NULL,l+1});
            }
            k++;
            
        }
        return;
    }
    
    bool find(int target) {
        if(st.find(target)==st.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */