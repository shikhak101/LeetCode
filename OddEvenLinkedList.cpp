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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* curr = head;
        ListNode* start = head;
        int k = 1;
        while(curr!=NULL) {
            int j = k;
            start = start->next;
            curr = start;
            int temp = start->val;
            if(curr!=NULL && curr->next!=NULL && (curr->next->next!=NULL || curr == head->next)) {
                while(j>0 && curr->next!=NULL) {
                    int p = temp;
                    curr = curr->next;
                    temp = curr->val;
                    curr->val = p;
                    j--;
                }
            }
            start->val = temp;
            k++;
            if(curr->next == NULL || curr->next->next == NULL) break;
        }
        return head;
    }
};
