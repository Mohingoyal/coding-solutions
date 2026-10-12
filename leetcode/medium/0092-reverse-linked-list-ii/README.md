# Reverse Linked List II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return  *the reversed list*.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

```

 **Example 2:** 

```
Input: head = [5], left = 1, right = 1
Output: [5]

```

 

 **Constraints:** 

- The number of nodes in the list is n.
- 1 <= n <= 500
- -500 <= Node.val <= 500
- 1 <= left <= right <= n

 

 **Follow up:**  Could you do it in one pass?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.3 MB (beats 38.55%)  
**Submitted:** 2026-10-12T18:03:16.830Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-linked-list-ii/)