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
ListNode* deletenode(ListNode* head,int &n,int &i)
{
    if(head==NULL)
    return NULL;
    head->next=deletenode(head->next,n,i);
    i=i+1;
    if(i==n)
    {
        return head->next;
    }
    return head;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        head=deletenode(head,n,i);
        return head;
    }
};