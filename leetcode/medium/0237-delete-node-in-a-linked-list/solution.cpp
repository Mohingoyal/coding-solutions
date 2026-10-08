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
    void deleteNode(ListNode* node) {
        ListNode* ptr=node;
        while(ptr!=NULL)
        {
            ptr->val=ptr->next->val;
            if(ptr->next->next==NULL)
        {
            ptr->next=NULL;
            
        }
            ptr=ptr->next;
        }
        return;
    }
};