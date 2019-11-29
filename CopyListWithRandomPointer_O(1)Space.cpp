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
        if(head == NULL) return NULL;
        Node* curr = head;
        while(curr != NULL) {
            Node* temp = new Node(curr->val,NULL,NULL);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        curr = head;
        Node* newhead = head->next;
        Node* newcurr = newhead;
        while(curr!=NULL && newhead!=NULL) {
            Node* t = curr->random;
            if(t!=NULL)
                newcurr->random = t->next;
            else newcurr->random = NULL;
            curr = newcurr->next;
            if(curr!=NULL)
                newcurr = curr->next;
        }
        newcurr = newhead;
        curr = head;
        while(curr != NULL && curr->next!=NULL) {
            curr->next = curr->next->next;
            curr = curr->next;
            if(newcurr!=NULL) {
                if(newcurr->next!=NULL)
                    newcurr->next = newcurr->next->next;
                newcurr = newcurr->next;
            }
        }
        return newhead;
    }
};