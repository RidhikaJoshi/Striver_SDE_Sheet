#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(r*c)
// Space Complexity: O(r*c)
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        int countOne=0;
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    countOne++;
            }
        }
        int delr[4]={-1,0,1,0};
        int delc[4]={0,-1,0,1};
        int count=0;
        while(q.size()!=0)
        {
            int size=q.size();
            int flag=0;
            for(int i=0;i<size;i++)
            {
                int currR=q.front().first;
                int currC=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int newR=currR+delr[k];
                    int newC=currC+delc[k];
                    if(newR>=0 && newR<r && newC>=0 && newC<c)
                    {
                        if(grid[newR][newC]==1)
                        {
                            flag=1;
                            countOne--;
                            q.push({newR,newC});
                            grid[newR][newC]=2;
                        }
                    }
                }
            }
            if(flag==1)
                count++;
        }
        if(countOne!=0)
            return -1;
        return count;
       
    }
};