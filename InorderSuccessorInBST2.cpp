/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* closestP = node->parent;
        Node* closestC = node->right;
        while(closestP!=NULL && closestP->val<node->val) {
            closestP = closestP->parent;
        }
        while(closestC!=NULL && closestC->left!=NULL) {
            closestC = closestC->left;
        }
        if(closestP == NULL && closestC == NULL) return NULL;
        if(closestP == NULL) return closestC;
        if(closestC == NULL) return closestP;
        if(closestP->val<closestC->val) return closestP;
        return closestC;
    }
};