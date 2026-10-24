# Number of Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return  *the number of islands*.

An  **island**  is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

 **Example 1:** 

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

```

 **Example 2:** 

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'.

## Solution

**Language:** C++  
**Runtime:** 23 ms (beats 83.92%)  
**Memory:** 16.7 MB (beats 56.23%)  
**Submitted:** 2026-10-24T05:08:30.317Z  

```cpp
class Solution {
public:
bool goup(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j)
{
    if(i-1<0||visited[i-1][j]==true||grid[i-1][j]=='0')
    return false;//nhi ja sakta
    return true;
}
bool goright(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j)
{
    if(j+1==grid[0].size()||visited[i][j+1]==true||grid[i][j+1]=='0')
    return false;//nhi ja sakta
    return true;
}
bool godown(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j)
{
    if(i+1==grid.size()||visited[i+1][j]==true||grid[i+1][j]=='0')
    return false;//nhi ja sakta
    return true;
}
bool goleft(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j)
{
    if(j-1<0||visited[i][j-1]==true||grid[i][j-1]=='0')
    return false;//nhi ja sakta
    return true;
}
bool findislands(vector<vector<char>>& grid, vector<vector<bool>> &visited,int &i,int &j)
{
    if(grid[i][j]=='0'||visited[i][j]==true)
    return false;
    visited[i][j]=true;
   bool recv;
   recv= goleft(grid,visited,i,j);
   if(recv==true)
   {int k=j-1;
    //    visited[i][j]=true;
    findislands(grid,visited,i,k);
   }
      recv= godown(grid,visited,i,j);
      if(recv==true)
   {
    int k=i+1;
        // visited[i][j]=true;
    findislands(grid,visited,k,j);
   }

     recv= goright(grid,visited,i,j);
      if(recv==true)
   {int k=j+1;
    //    visited[i][j]=true;
    findislands(grid,visited,i,k);
   }
     recv= goup(grid,visited,i,j);
      if(recv==true)
   {int k=i-1;
    //    visited[i][j]=true;
    findislands(grid,visited,k,j);
   }
    return true;
}
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
       for(int i=0;i<grid.size();i++)
       {
        for(int j=0;j<grid[i].size();j++)
        {
            bool recv=findislands(grid,visited,i,j);
            if(recv==true)
            ans++;
        }
       }
       return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-islands/)