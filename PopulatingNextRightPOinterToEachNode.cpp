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
        if(root == NULL || root->left == NULL) return root;
        solution(root->left, root->right);
        return root;
    }
    void solution(Node* currL, Node* currR)
    {
        if(currL == NULL) return;
        currL->next = currR;
        Node* rMost = currL;
        Node* lMost = currR;
        while(lMost->left != NULL)
        {
            lMost = lMost->left;
            rMost = rMost->right;
            rMost->next = lMost;
        }
        solution(currL->left,currL->right);
        solution(currR->left, currR->right);
    }
};