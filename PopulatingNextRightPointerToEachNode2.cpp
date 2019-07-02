/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        Node* lastNode = root;
        Node* curr = root;
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
            if(curr == lastNode && !q.empty())
            {
                curr->next = NULL;
                lastNode = q.back();
            }
            else if(!q.empty())
            {
                curr->next = q.front();
            }
        }
        return root;
    }
};