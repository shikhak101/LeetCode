/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head;
        while(curr!=NULL && curr->next != NULL) {
            ListNode* i = curr->next;
            int item = i->val;
            ListNode* j = head;
            ListNode* loc = NULL;
            int prev =0;
            while(j!=i){
                if(j->val > item) {
                    if(loc == NULL){
                        loc = j;
                        prev = j->next->val;
                        j->next->val = j->val;
                    }
                    else{
                        int p = j->next->val;
                        j->next->val = prev;
                        prev = p;
                    }
                }
                j = j->next;
            }
            if(loc!=NULL) loc->val = item;   
            curr = curr->next;
        }
        return head;
    }
};