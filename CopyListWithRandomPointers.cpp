/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mapping_rand;
        Node* curr = head;
        Node* prev = NULL;
        Node* newhead = NULL;
        while(curr != NULL) {
            Node* temp = NULL;
            temp = new Node(curr->val,NULL,NULL);
            if(prev!=NULL) {
                prev->next = temp;
            }
            else {
                newhead = temp;
            }
            mapping_rand.insert({curr,temp});
            curr = curr->next;
            prev = temp;
        }
        curr = head;
        Node* newcurr = newhead;
        while(curr!=NULL) {
            Node* t = curr->random;
            Node* newt = mapping_rand[t];
            newcurr->random = newt;
            curr = curr->next;
            newcurr = newcurr->next;
        }
        return newhead;
    }
};