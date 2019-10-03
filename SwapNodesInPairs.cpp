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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!= NULL && curr->next!=NULL){
            ListNode* first = curr;
            ListNode* second = curr->next;
            ListNode* c_next = curr->next->next;
            second->next = first;
            first->next= c_next;
            if(prev != NULL) {
                prev->next = second;
            }
            else{
                head = second;
            }
            prev = first;
            curr = c_next;
        }
        return head;
    }
};