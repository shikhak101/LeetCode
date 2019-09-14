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
    const char emptySymbol;
    const char seperator;
    Codec(): emptySymbol('#'), seperator(',') {} 
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        treeToStr(root, res);
        res.erase(res.cbegin());
        return res;
    }
    void treeToStr(TreeNode* root, string& res) {
        res.push_back(seperator);
        if (root == NULL) {
            res.push_back(emptySymbol);
        }
        else {
            res.append(std::to_string(root->val));
            treeToStr(root->left, res);
            treeToStr(root->right, res);
        }
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<string> dq;
        string tmp;
        stringstream ss(data);
        while(getline(ss, tmp, seperator)) {
            dq.push_back(tmp);
        }
        return strToTree(dq);
    }
    
    TreeNode* strToTree(deque<string>& data) {
        string rootVal = data.front();
        data.pop_front();
        if (rootVal.compare("#") == 0)
            return NULL;
        else {
            TreeNode* root = new TreeNode(std::stoi(rootVal));
            root->left = strToTree(data);
            root->right = strToTree(data);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));