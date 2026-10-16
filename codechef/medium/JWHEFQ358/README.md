# JWHEFQ358

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Identical Binary Trees

Given two undirected binary trees T1 and T2, check if they are the identical or not.

Two binary trees are considered identical if they are structurally same, and the nodes have the same value.

For example, the following two binary trees are identical:

### Input Format
- The first line of the input contains two space separated integers $N$ and $M$ — the number of nodes in the two binary trees.
- Next $N - 1$ lines contain three space separated characters $p1_i, c1_i, R_i$, describing the first tree with edge informations - $p1_i$ is an integer denoting the parent node of the $i$th edge, $c1_i$ is child node, and the letter $R_i$ denotes whether the child is left child or right child, it's value is L if $c1_i$ is left child of $p1_i$, else R.
- Similarly, next $M - 1$ lines contain three space separated characters $p2_i, c2_i, R_i$, describing the second tree with edge informations - $p2_i$ is an integer denoting the parent node of the $i$th edge, $c2_i$ is child node, and the letter $R_i$ denotes whether the child is left child or right child, it's value is L if $c2_i$ is left child of $p2_i$, else R.
### Output Format

Output on the single line, `YES` if the two trees are identical else `NO` otherwise.

### Constraints
- $1 \leq N, M \leq 10000$
- $1 \leq p1_i, p2_i, c1_i, c2_i \leq 100000$
- $R_i$ = L or R
- All $p_i$'s and $c_i$'s are distinct.
### Sample 1:
Input
Output

```
5 5
1 2 L
1 3 R
3 4 L
3 5 R
1 2 L
1 3 R
3 4 L
3 5 R
```

```
YES
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-16T03:55:47.691Z  

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
  bool same(Node* root1,Node* root2)
  {
      if(root1==NULL&&root2==NULL)
      return true;
      if(root1==NULL&&root2!=NULL)
      return false;
      if(root1!=NULL&&root2==NULL)
      return false;
      bool recv1=same(root1->left,root2->left);
      if(recv1==false)
      return false;
      if(root1->val!=root2->val)
      return false;
      bool recv2=same(root1->right,root2->right);
      if(recv2==false)
      return false;
      if(root1->val!=root2->val)
      return false;
      return true;
  }
    void isIdenticalTrees(Node* root1, Node* root2) {
        // your code goes here
        bool recv1=same(root1,root2);
        if(recv1==true)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
};


void inOrder(Node* root, vector<int> &nodes){
    if(root == NULL)
      return;
    inOrder(root -> left, nodes);
    nodes.push_back(root->val);
    inOrder(root -> right, nodes);
}
void preOrder(Node* root, vector<int> &nodes){
    if(root == NULL)
      return;
    nodes.push_back(root->val);
    preOrder(root -> left, nodes);
    preOrder(root -> right, nodes);
}

Node* buildBinaryTree(vector<pair<pair<int, int>, char>>& edges) {
    map<int, Node*> nodes;
    set<Node*> children;

    // Create nodes for each edge
    for (const auto& edge : edges) {
        int parentVal = edge.first.first, childVal = edge.first.second;
        char direction = edge.second;

        Node* parentNode;
        Node* childNode;

        // Check if the parent node already exists
        if (nodes.find(parentVal) == nodes.end()) {
            parentNode = new Node(parentVal);
            nodes[parentVal] = parentNode;
        } else {
            parentNode = nodes[parentVal];
        }

        // Similarly create the child node if not already created
        if(nodes.find(childVal) == nodes.end()) {
          childNode = new Node(childVal);
          nodes[childVal] = childNode;
        }
        else {
          childNode = nodes[childVal];
        }
        

        // Attach the child node to the parent based on the direction
        if (direction == 'L') {
            parentNode->left = childNode;
        } else {
            parentNode->right = childNode;
        }

        // Update the set with the child node
        children.insert(childNode);
    }

    // The root of the binary tree is the node without a parent
    Node* root = NULL;
    for (const auto& it : nodes) {
        if (children.find(it.second) == children.end()) {
            root = it.second;
            break;
        }
    }
    return root;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
    int n, m;
    cin >> n >> m;
    assert(n >= 1 && n <= 10000);
    assert(m >= 1 && m <= 10000);
    if(n==1 && m==1){
        cout<<"YES\n";
        return 0;
    }
    if(m==1){
        cout<<"NO\n";
        return 0;
    }
    if(n==1){
        cout<<"NO\n";
        return 0;
    }

    vector<int> inorder1, inorder2;
    vector<pair<pair<int, int>, char > > edges1, edges2;

    set<int> unique_nodes1, unique_nodes2;
    
    for(int i = 1; i < n; i++){
        int p, c;
        char r;
        cin >> p >> c >> r;
        assert(p >= 1 && p <= 100000);
        assert(c >= 1 && c <= 100000);
        assert(r == 'L' || r == 'R');
        unique_nodes1.insert(p);
        unique_nodes1.insert(c);
        edges1.push_back({{p, c}, r});
    }

    for(int i = 1; i < m; i++){
        int p, c;
        char r;
        cin >> p >> c >> r;
        assert(p >= 1 && p <= 100000);
        assert(c >= 1 && c <= 100000);
        assert(r == 'L' || r == 'R');
        unique_nodes2.insert(p);
        unique_nodes2.insert(c);
        edges2.push_back({{p, c}, r});
    }

    assert(unique_nodes1.size() == n);
    Node* root1 = buildBinaryTree(edges1);
    inOrder(root1, inorder1);
    assert(inorder1.size() == n);
    
    assert(unique_nodes2.size() == m);
    Node* root2 = buildBinaryTree(edges2);
    inOrder(root2, inorder2);
    assert(inorder2.size() == m);
    Solution sol;
    sol.isIdenticalTrees(root1, root2);
    
    inorder1.clear();
    inOrder(root1, inorder1);
    assert(inorder1.size() == n);

    inorder2.clear();
    inOrder(root2, inorder2);
    assert(inorder2.size() == m);


    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/JWHEFQ358)