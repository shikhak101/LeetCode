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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* slow = head; ListNode* fast = head;
        ListNode* curr = head;
        int len = 0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        k = k%len;
        while(k>0){
            fast = fast->next;
            k--;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};