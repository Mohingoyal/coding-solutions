# Swap Nodes in Pairs

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

 **Example 1:** 

 **Input:**  head = [1,2,3,4]

 **Output:**  [2,1,4,3]

 **Explanation:** 

 **Example 2:** 

 **Input:**  head = []

 **Output:**  []

 **Example 3:** 

 **Input:**  head = [1]

 **Output:**  [1]

 **Example 4:** 

 **Input:**  head = [1,2,3]

 **Output:**  [2,1,3]

 

 **Constraints:** 

- The number of nodes in the list is in the range [0, 100].
- 0 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11 MB (beats 86.23%)  
**Submitted:** 2026-10-07T04:25:55.878Z  

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
```

---

[View on LeetCode](https://leetcode.com/problems/swap-nodes-in-pairs/)