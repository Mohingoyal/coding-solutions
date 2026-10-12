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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL)
        return NULL;
        if(head->next==NULL)
        return head;
        if(left==right)
        return head;
        ListNode* sptr=head;
        ListNode* fptr=head;
        for(int i=1;i<left-1;i++)
        {
            sptr=sptr->next;
        }
         for(int i=1;i<right;i++)
        {
            fptr=fptr->next;
        }
        ListNode* headfirst=sptr->next;
        ListNode* headafterlast=fptr->next;
        fptr->next=NULL;
        sptr->next=NULL;
        ListNode* ptr=headfirst;
        ListNode* prev=NULL;
        ListNode* store;
        while(ptr!=NULL)
        {
         store=ptr->next;
         ptr->next=prev;
         prev=ptr;
         ptr=store;

        }
        if(left!=1)
        {sptr->next=prev;
        headfirst->next=headafterlast;}
        else if(left==1)//pehle node pe hi badlav karna hai
        {
            head=prev;
            headfirst->next=sptr;
            sptr->next=headafterlast;
        }
        return head;
    }
};