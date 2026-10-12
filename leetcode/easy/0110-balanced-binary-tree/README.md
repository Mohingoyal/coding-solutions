# Balanced Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a binary tree, determine if it is  **height-balanced**.

 

 **Example 1:** 

```
Input: root = [3,9,20,null,null,15,7]
Output: true

```

 **Example 2:** 

```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

```

 **Example 3:** 

```
Input: root = []
Output: true

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 5000].
- -104 <= Node.val <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 23.1 MB (beats 20.01%)  
**Submitted:** 2026-10-12T13:20:12.981Z  

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
int height(TreeNode* root,bool &result)
{
    if(root==NULL)
    return 0;
  
int hleft=height(root->left,result);
int hright=height(root->right,result);
if(!(abs(hleft-hright)==1||abs(hleft-hright)==0))
result=false;
int x=max(hleft,hright)+1;
return x;
}
    bool isBalanced(TreeNode* root) {
        bool result=true;
        height(root,result);
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/balanced-binary-tree/)