# Binary Tree Zigzag Level Order Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, return  *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

 

 **Example 1:** 

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

```

 **Example 2:** 

```
Input: root = [1]
Output: [[1]]

```

 **Example 3:** 

```
Input: root = []
Output: []

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 2000].
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.2 MB (beats 47.99%)  
**Submitted:** 2026-10-17T05:00:22.338Z  

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        queue<TreeNode* > q;
        q.push(root);
     
        int level=0;
        while(!q.empty())
        {vector<int> temp;
        int size=q.size();
        for(int i=0;i<size;i++)
        {TreeNode* ptr=q.front();
            temp.push_back(q.front()->val);
            q.pop();
            
                 if(ptr->left!=NULL)
                q.push(ptr->left);
                    if(ptr->right!=NULL)
                q.push(ptr->right);
            
        }
        if(level%2==0)
        {
            ans.push_back(temp);
        }
        else{
            for(int i=0;i<temp.size()/2;i++)
            {
               swap(temp[i],temp[temp.size()-1-i]);
            }
            ans.push_back(temp);
        }
        level++;
    
             
        }
        return ans;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)