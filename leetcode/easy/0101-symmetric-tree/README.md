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
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-10-12T13:33:46.882Z  

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
void getarray(TreeNode* root,vector<int> &ary)
{
    if(root==NULL)
    return;
    getarray(root->left,ary);
    ary.push_back(root->val);
    getarray(root->right,ary);
    return;
}
    bool isSymmetric(TreeNode* root) {
        vector<int> ary;
        getarray(root,ary);
        if(ary.size()%2==0)
        return false;
        for(int i=0;i<ary.size()/2;i++)
        {
            if(ary[ary.size()-1-i]!=ary[i])
            return false;
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/symmetric-tree/)