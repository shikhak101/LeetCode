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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextnode = NULL;
        while(curr!=NULL) {
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        
        return prev;
    }
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        ListNode* t = head;
        while(t!=NULL) {
            if(t->val == 9)
            {
                 cout<<t->val<<endl;
                t->val = 0;
                if(t->next == NULL) {
                    ListNode* temp = NULL;
                    temp = new ListNode(1);
                    t->next = temp;
                    break;
                }
                t = t->next;
            }
            else {
                t->val++;
                break;
            }
        }
        head = reverse(head);
        return head;
    }
};