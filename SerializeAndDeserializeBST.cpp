/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val);
        while(!q.empty()) {
            TreeNode* node = q.front();
            if(node!=NULL && node!=root)
                s += "," + to_string(node->val);
            else if(node == NULL) s+=",null";
            q.pop();
            if(node!=NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string dd) {
        if(dd.size() == 0) return NULL;
        TreeNode* root = NULL;
        vector<string> arr;
        stringstream data(dd);
        string line;
        while(getline(data,line,',')) {
            arr.push_back(line);
        }
        root = new TreeNode(stoi(arr[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node!=NULL) {
                TreeNode* l = NULL;
                if(i<arr.size() && arr[i].compare("null")!=0)
                    l = new TreeNode(stoi(arr[i]));
                i++;
                node->left = l;
                q.push(node->left);
                TreeNode* r = NULL;
                if(i<arr.size() && arr[i].compare("null")!=0)
                    r = new TreeNode(stoi(arr[i]));
                i++;
                node->right = r;
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));