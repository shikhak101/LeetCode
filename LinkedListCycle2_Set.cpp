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
        set<ListNode*> st;
        while(head!=NULL) {
            int currsize = st.size();
            st.insert(head);
            if(st.size() == currsize) return head;
            head = head->next;
        }
        return head;
    }
};