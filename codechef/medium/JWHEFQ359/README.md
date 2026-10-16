# JWHEFQ359

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Mirror Tree

Given a binary tree, check whether it is a structural mirror of itself (i.e., structurally symmetric around its center).

For example, the following binary tree is structurally symmetric:

### Input Format
- The first line of the input contains a single integer $N$ — the number of nodes in the binary tree.
- Next $N - 1$ lines contain three space separated characters $p_i, c_i, R_i$, describing the tree with edge informations - $p_i$ is an integer denoting the parent node of the $i$th edge, $c_i$ is child node, and the letter $R_i$ denotes whether the child is left child or right child, it's value is L if $c_i$ is left child of $p_i$, else R.
### Output Format

Output on the single line, `YES` if the given binary tree is structurally symmetric to itself, `NO` otherwise.

### Constraints
- $1 \leq N \leq 10000$
- $1 \leq p_i, c_i \leq 100000$
- $R_i$ = L or R
- All $p_i$'s and $c_i$'s are distinct.(No same pairs are given twice)
### Sample 1:
Input
Output

```
7
1 2 L
1 3 R
3 4 L
3 5 R
2 6 R
2 7 L
```

```
YES
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-16T04:01:47.043Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  bool checksym(Node* root1,Node* root2)
  {
      if(root1==NULL&&root2==NULL)
      return true;//barabary di gal baat
      if(root1!=NULL&&root2==NULL)
      return false;
      if(root1==NULL&&root2!=NULL)
      return false;
      bool recv1=checksym(root1->left,root2->right);
      if(recv1==false)
      return false;
      bool recv2=checksym(root1->right,root2->left);
      if(recv2==false)
      return false;
      return true;
  }
    void isMirrorTree(Node* root) {
        // Complete this function
        
        bool recv1=checksym(root,root);
        if(recv1==true)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
};

Node* nodes[100005];
bool hasParent[100005];
// --- Main Code and Suffix ---
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    if (n == 0) {
        cout << "YES\n";
        return 0;
    }
    
    memset(nodes, 0, sizeof(nodes));
    memset(hasParent, 0, sizeof(hasParent));
    
    for (int i = 0; i < n - 1; i++) {
        int p, c;
        char r;
        cin >> p >> c >> r;
        if (!nodes[p]) nodes[p] = new Node(p);
        if (!nodes[c]) nodes[c] = new Node(c);
        if (r == 'L') {
            nodes[p]->left = nodes[c];
        } else {
            nodes[p]->right = nodes[c];
        }
        hasParent[c] = true;
    }
    
    Node* root = NULL;
    // Find the root (node that has been created but has no parent)
    for (int i = 1; i <= 100000; i++) {
        if (nodes[i] && !hasParent[i]) {
            root = nodes[i];
            break;
        }
    }
    
    // If N = 1, there are 0 edges, the root is node 1
    if (!root && n == 1) {
        root = new Node(1);
    }
    
    Solution sol;
    sol.isMirrorTree(root);
    
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/JWHEFQ359)