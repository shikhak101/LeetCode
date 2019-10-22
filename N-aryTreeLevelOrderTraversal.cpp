/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        queue<int> level;
        vector<vector<int>> res;
        if(root==NULL) return res;
        q.push(root);
        level.push(0);
        int prev = 0;
        vector<int> temp;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            int l = level.front();
            level.pop();
            if(l != prev) {
                res.push_back(temp);
                temp.clear();
            }
            temp.push_back(curr->val);
            prev = l;
            for(int i=0; i<curr->children.size(); i++) {
                q.push(curr->children[i]);
                level.push(l+1);
            }
        }
        if(temp.size()>0) res.push_back(temp);
        return res;
    }
};