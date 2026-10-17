# JWHEFQ360

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Level Order Traversal

Given a binary tree, print the level order traversal of its nodes. (i.e., from left to right, on each level).

For example, the level order traversal of the following binary tree is:
1
2 3
4 5

### Input Format
- The first line of the input contains a single integer $N$ — the number of nodes in the binary tree.
- Next $N - 1$ lines contain three space separated characters $p_i, c_i, R_i$, describing the tree with edge informations - $p_i$ is an integer denoting the parent node of the $i$th edge, $c_i$ is child node, and the letter $R_i$ denotes whether the child is left child or right child, it's value is L if $c_i$ is left child of $p_i$, else R.
### Output Format

Output on the L separate lines, $N$ space separated integers - its nodes in the level order traversal of the given tree, where L is total no. of levels in the given tree.

### Constraints
- $1 \leq N \leq 10000$
- $1 \leq p_i, c_i \leq 100000$
- $R_i$ = L or R
- All $p_i$'s and $c_i$'s are distinct.
### Sample 1:
Input
Output

```
5
1 2 L
1 3 R
3 4 L
3 5 R

```

```
1
2 3
4 5
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-17T04:24:35.268Z  

```c_cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void levelOrder(Node* root) {
        //write your code here 
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* ptr;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                cout<<q.front()->val<<" ";
                ptr=q.front();
                q.pop();
                if(ptr->left!=NULL)
                {
                    q.push(ptr->left);
                }
                if(ptr->right!=NULL)
                {
                    q.push(ptr->right);
                }
            }
            cout<<endl;
          
            
        }
        
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
    sol.levelOrder(root);
    
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/JWHEFQ360)