# Kth Smallest Element in a BST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary search tree, and an integer `k`, return  *the*  `kth`  *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

 

 **Example 1:** 

```
Input: root = [3,1,4,null,2], k = 1
Output: 1

```

 **Example 2:** 

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

```

 

 **Constraints:** 

- The number of nodes in the tree is n.
- 1 <= k <= n <= 104
- 0 <= Node.val <= 104

 

 **Follow up:**  If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 24.2 MB (beats 90.07%)  
**Submitted:** 2026-11-22T10:26:09.587Z  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int getbkst(TreeNode* root,int &counter,int & k)
{
    if(root==NULL)
    return -1;
    int recv;
    recv=getbkst(root->left,counter,k);
    if(recv!=-1)
    return recv;
    if(counter==k)
    return root->val;
    counter++;
    recv=getbkst(root->right,counter,k);

    return recv;
}
    int kthSmallest(TreeNode* root, int k) {
        int counter=1;
       int ans= getbkst(root,counter,k);
       return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)