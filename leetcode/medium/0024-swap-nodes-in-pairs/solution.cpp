/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* store1=head->next;
        ListNode* store2=head;
        head->next=head->next->next;
        head=store1;
        head->next=store2;
        ListNode *ptr=head->next;
        while(ptr!=NULL&&ptr->next!=NULL&&ptr->next->next!=NULL)
        {
         ListNode* ptr1=ptr->next;
         ListNode* ptr2=ptr->next->next;
         ptr1->next=ptr2->next;
         ptr->next=ptr2;
ptr2->next=ptr1;
ptr=ptr->next->next;

        }
        return head;
    }
};