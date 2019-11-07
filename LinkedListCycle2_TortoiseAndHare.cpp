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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow!=fast || (slow == head && slow->next == NULL)) return NULL;
        ListNode* p1 = head;
        ListNode* p2 = slow;
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        cout<<p1->val;
        return p1;
    }
};