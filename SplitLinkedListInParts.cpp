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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = 0;
        ListNode* curr = root;
        while(curr != NULL) {
            size++;
            curr = curr->next;
        }
        int each = size/k;
        int extra = size%k;
        vector<ListNode*> res;
        curr = root;
        for(int i=0; i<k; i++) {
            ListNode* temp = NULL;
            ListNode* temphead = NULL;
            int n = each;
            if(extra > 0) {
                n++; extra--;
            }
            ListNode* prev = NULL;
            for(int j=0; j<n; j++) {
                temp = new ListNode(curr->val);
                curr = curr->next;
                if(prev != NULL) {
                    prev->next = temp;
                }
                prev = temp;
                if(temphead == NULL) {
                    temphead = temp;
                }
            }
            res.push_back(temphead);
        }
        return res;
    }
};