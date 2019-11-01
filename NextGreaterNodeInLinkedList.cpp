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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode* curr = head;
        while(curr->next!=NULL) {
            int v = curr->val;
            ListNode* t = curr->next;
            while(t!=NULL) {
                if(t->val > v) {
                    res.push_back(t->val);
                    break;
                }
                t = t->next;
            }
            if(t == NULL) res.push_back(0);
            curr = curr->next;
        }
        res.push_back(0);
        return res;
    }
};