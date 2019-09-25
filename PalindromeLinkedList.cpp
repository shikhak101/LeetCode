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
    ListNode* reverse(ListNode* curr) {
        ListNode* prev = NULL;
        while(curr!=NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL && fast->next == NULL){
            prev = slow;
            slow = slow->next;
        }
        prev->next = reverse(slow);
        ListNode* begin = head;
        ListNode* mid = prev->next;
        while(mid != NULL) {
            if(mid->val != begin->val) return false;
            mid = mid->next;
            begin= begin->next;
        }
        return true;
    }
};