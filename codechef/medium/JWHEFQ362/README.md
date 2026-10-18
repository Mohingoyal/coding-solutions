# JWHEFQ362

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Boundary of the Binary Tree

Given a binary tree, print the boundary nodes of it in an  **Anti-Clockwise**  direction, starting from the root. The boundary encompasses:

- Left boundary (nodes on the left, excluding leaf nodes).
- Leaves (comprising solely the leaf nodes).
- Right boundary (nodes on the right, excluding leaf nodes).

For eg., in the above tree:
 **root:**  1
 **left boundary nodes:**  2
 **leaf nodes:**  6 8 4 5
 **right boundary nodes:**  3
Hence the output should be: 1 2 6 8 4 5 3

### Input Format
- The first line of the input contains a single integer $N$ — the number of nodes in the binary tree.
- Next $N - 1$ lines contain three space separated characters $p_i, c_i, R_i$, describing the tree with edge informations - $p_i$ is an integer denoting the parent node of the $i$th edge, $c_i$ is child node, and the letter $R_i$ denotes whether the child is left child or right child, it's value is L if $c_i$ is left child of $p_i$, else R.
### Output Format

Print on the single line, $K$ (if there are $K$ nodes in the tree's boundary) space separated nodes values - the boundary nodes of the given binary tree in an  **Anti-Clockwise**  direction

### Constraints
- $1 \leq N \leq 10000$
- $1 \leq p_i, c_i \leq 100000$
- $R_i$ = L or R
- All $p_i$'s and $c_i$'s are distinct.
### Sample 1:
Input
Output

```
8
1 2 L
1 3 R
3 4 L
3 5 R
2 6 L
2 7 R
7 8 R
```

```
1 2 6 8 4 5 3
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-18T11:22:02.987Z  

```c_cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
    int val; 
    Node *left;
    Node *right;

    Node(int node_value) {
        val = node_value;
        left = right = NULL;
    }
};

class Solution {
  public:
  void getleft(Node* root)
  {
      if(root==NULL)
      return ;
      if(root->left!=NULL&&root->right!=NULL)
      cout<<root->val<<" ";
      getleft(root->left);
   
    return;
      
  }
  void getnodes(Node* root)
  {
      if(root==NULL)
      return;
      if(root->left==NULL&&root->right==NULL)
      {
          cout<<root->val<<" ";
          return;
      }
      getnodes(root->left);
      getnodes(root->right);
      return;
  }
  void getright(Node* root)
  {
      if(root==NULL)
      return;
      if(root->left!=NULL&&root->right!=NULL)
      cout<<root->val<<" ";
     
      getright(root->right);
      return;
  }
    void printBoundary(Node* root) {
        // your code goes here//extreme left leni h
        if(root==NULL)
        return;
        getleft(root);
        getnodes(root);
        getright(root->right);
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    Node* root = nullptr;
    if (n == 1) {
        root = new Node(1);
    } else {
        unordered_map<int, Node*> nodeMap;
        unordered_set<int> children;
        
        for (int i = 0; i < n - 1; ++i) {
            int p, c;
            char direction;
            cin >> p >> c >> direction;
            
            if (nodeMap.find(p) == nodeMap.end()) {
                nodeMap[p] = new Node(p);
            }
            if (nodeMap.find(c) == nodeMap.end()) {
                nodeMap[c] = new Node(c);
            }
            
            if (direction == 'L') {
                nodeMap[p]->left = nodeMap[c];
            } else {
                nodeMap[p]->right = nodeMap[c];
            }
            children.insert(c);
        }
        
        for (auto const& [key, val] : nodeMap) {
            if (children.find(key) == children.end()) {
                root = val;
                break;
            }
        }
    }
    
    Solution sol;
    sol.printBoundary(root);
    
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/JWHEFQ362)