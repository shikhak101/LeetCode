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
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        while(head!=NULL) {
            if(find(G.begin(), G.end(),head->val) != G.end()) {
                res++;
                head = head->next;
                while(head!=NULL) {
                    if(find(G.begin(), G.end(),head->val) != G.end()) {
                        head = head->next;
                    }
                    else break;
                }
            }
            else head = head->next;
        }
        return res;
    }
};