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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL; ListNode* prev = NULL;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<lists.size(); i++){
            while(lists[i]!=NULL){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        while(!pq.empty()){
            ListNode* ln = NULL;
            ln = new ListNode(pq.top());
            pq.pop();
            if(res == NULL){
                res = ln;
            }
            else {
                prev->next = ln;
            }
            prev = ln;
            
        }
        return res;
    }
};