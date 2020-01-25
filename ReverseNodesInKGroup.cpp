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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1 || head==NULL) return head;
        ListNode* last= head;
        int c = 1;
        while(c<k){
            c++;
            last = last->next;
            if(last == NULL) return head;
        }
        ListNode* newhead = last->next;
        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* nextnode = NULL;
        while(curr!=last){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        curr->next = prev;
        head->next = reverseKGroup(newhead,k);
        return last;
    }
};