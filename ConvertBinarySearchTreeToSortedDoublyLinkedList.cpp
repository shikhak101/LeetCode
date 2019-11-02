/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* first = NULL;
    Node* last = NULL;
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        solution(root);
        first->left = last;
        last->right = first;
        return first;
    }
    void solution(Node* root) {
        if(root==NULL) return;
        solution(root->left);
        if(last!=NULL) {
            last->right = root;
            root->left = last;
        }
        else first = root;
        last = root;
        solution(root->right);
    }
};