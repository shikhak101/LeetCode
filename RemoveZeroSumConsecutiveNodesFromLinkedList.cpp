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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev = NULL;
        while(start!=NULL) {
            int sum = 0;
            sum += start->val;
            end = start->next;
            if(start->val == 0){
                if(prev == NULL) head = head->next;
                else prev->next = start->next;
            }
            while(end != NULL) {
                sum += end->val;
                if(sum == 0) {
                    if(prev == NULL) head = end->next;
                    else {
                        prev->next = end->next;
                    }
                }
                end = end->next;
            }
            prev = start;
            start = start->next;
            
        }
        return head;
    }
};