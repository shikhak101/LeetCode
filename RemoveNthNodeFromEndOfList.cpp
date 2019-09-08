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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* prev = NULL;
        ListNode* fast = head;
        int count = 1;
        if(head == NULL) return head;
        while(fast->next != NULL && count < n) {
            count ++;
            fast = fast->next;            
        }
        while(fast->next != NULL) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev == NULL) {
            head = head->next;
        }
        else {
            prev->next = slow->next;
        }
        return head;
    }
};