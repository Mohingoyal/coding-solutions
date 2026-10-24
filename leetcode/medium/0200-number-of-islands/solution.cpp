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