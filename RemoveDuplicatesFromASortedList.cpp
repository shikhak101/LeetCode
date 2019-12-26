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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL) {
            int v = curr->val;
            int c = 0;
            ListNode* t = curr;
            while(t!=NULL && t->val == v) {
                t = t->next;
                c++;
            }
            if(c==1) {
                prev = curr;
                curr = curr->next;
            }
            else if(c>1) {
                if(prev == NULL) {
                    head = t;
                    curr = t;
                }
                else {
                    prev->next = t;
                    curr = t;
                }
            }
        }
        return head;
    }
};