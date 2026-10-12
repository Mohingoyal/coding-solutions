# Symmetric Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree,  *check whether it is a mirror of itself*  (i.e., symmetric around its center).

 

 **Example 1:** 

```
Input: root = [1,2,2,3,4,4,3]
Output: true

```

 **Example 2:** 

```
Input: root = [1,2,2,null,3,null,3]
Output: false

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 1000].
- -100 <= Node.val <= 100

 

 **Follow up:**  Could you solve it both recursively and iteratively?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 18.6 MB (beats 14.18%)  
**Submitted:** 2026-10-12T14:02:53.846Z  

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
bool mirrortree(TreeNode* root1,TreeNode* root2)
{bool var;
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1==NULL||root2==NULL)
    return false;
    if(root1->val==root2->val)
    {
       var= mirrortree(root1->left,root2->right);
       if(var==false)
       return false;
        var=mirrortree(root1->right,root2->left);
        if(var==false)
        return false;
    }
    else var=false;
     return var;
}
    bool isSymmetric(TreeNode* root) {
        return mirrortree(root,root);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/symmetric-tree/)