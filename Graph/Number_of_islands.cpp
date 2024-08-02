#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(rows*col)
// Space Complexity: O(rows*col)
class Solution {
public:
    
    void dfs(int currR,int currC,vector<vector<char>>& grid, vector<vector<int>>&vis,int rows,int col)
    {
        vis[currR][currC]=1;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,-1,0,1};
        for(int k=0;k<4;k++)
        {
            int newR=currR+delr[k];
            int newC=currC+delc[k];
            if(newR>=0 && newR<rows && newC>=0 && newC<col)
            {
                if(vis[newR][newC]==0 && grid[newR][newC]=='1')
                    dfs(newR,newC,grid,vis,rows,col);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int rows=grid.size();
        int col=grid[0].size();
        int islands=0;
        vector<vector<int>>vis(rows,vector<int>(col,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    islands++;
                    dfs(i,j,grid,vis,rows,col);

                }
            }
        }
        return islands;
        
    }
};