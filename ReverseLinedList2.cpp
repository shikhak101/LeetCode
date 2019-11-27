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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* curr = head;
        ListNode* parent = NULL;
        int m1 = m;
        while(m1-1>0) {
            parent = curr;
            curr= curr->next;
            m1--;
        }
        ListNode* begin = curr;
        int n1 = n-m;
        ListNode* prev = NULL;
        
        while(n1>=0) {
            n1--;
            if(prev == NULL) {
                prev = curr;
                curr = curr->next;
            }
            else {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
        }
        begin->next = curr;
        if(parent!=NULL) {
            parent->next = prev;
        }
        else {
            head = prev;
        }
        return head;
    }
};