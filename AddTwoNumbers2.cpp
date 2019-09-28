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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1; stack<int> s2;
        while(l1!=NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* head = NULL;
        while(!s1.empty() && !s2.empty()) {
            int sum = s1.top() + s2.top() + carry;
            carry = sum/10;
            int val = sum%10;
            ListNode* temp = NULL;
            temp = new ListNode(val);
            s1.pop(); s2.pop();
            temp->next = head;
            head = temp;
        }
        if(!s2.empty()) s1 = s2;
        while(!s1.empty()){
            int sum = s1.top() + carry;
            carry = sum/10;
            int val = sum%10;
            ListNode* temp = NULL;
            temp = new ListNode(val);
            s1.pop();
            temp->next = head;
            head = temp;
        }
        
        if(carry>0){
            ListNode* temp = NULL;
            temp = new ListNode(carry);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};