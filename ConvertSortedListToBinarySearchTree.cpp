/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* curr = head;
        int size = 0;
        while(curr != NULL){
            curr = curr->next;
            size++;
        }
        int mid = (size-1)/2;
        curr = head;
        ListNode* leftt = curr;
        ListNode* temp = leftt;
        ListNode* rightt = curr;
        TreeNode* root = NULL;
        if(mid == 0) leftt = NULL;
        while(curr!= NULL && mid > 0){
            temp = curr;
            curr = curr->next;
            mid--;
        }
        cout<<curr->val;
        if(curr!=NULL){
            TreeNode* newnode =new TreeNode(curr->val);
            root = newnode;
            rightt = curr->next;
        }
        temp->next = NULL;
        if(root!=NULL){
            root->left = sortedListToBST(leftt);
            root->right = sortedListToBST(rightt);
            cout<<root->val<<"--";
        }
        
        return root;
        
        
    }
};