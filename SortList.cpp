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
    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            if(fast->next!=NULL)
                fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergesort(ListNode* a, ListNode* b) {
        if(a!=NULL && b!=NULL){ 
            if(a->val<b->val) {
                a->next = mergesort(a->next,b);
                return a;
            }
            else {
                b->next = mergesort(a,b->next);
                return b;
            }
        }
        else if(a!=NULL) return a;
        else if(b!=NULL) return b;
        return NULL;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* mid = findmid(head);
        ListNode* secondst;
        if(mid!=NULL) {
            secondst = mid->next;
            mid->next = NULL;
        }
        return mergesort(sortList(head),sortList(secondst));
    }
    
};