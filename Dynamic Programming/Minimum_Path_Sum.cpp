#include<bits/stdc++.h>
using namespace std;
// Recursive Solution
// Time Complexity: O(2^(r*c))
// Space Complexity: Recursion Stack
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        int up=INT_MAX,left=INT_MAX;
        // moving up
        if(i-1>=0)
            up=helper(i-1,j,grid);
        if((j-1)>=0)
            left=helper(i,j-1,grid);

        return grid[i][j]+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        return helper(r-1,c-1,grid);
        
    }
};
// Memoization Solution
// Time Complexity: O(r*c)
// Space Complexity: O(r*c)+Recursion Stack
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=INT_MAX,left=INT_MAX;
        // moving up
        if(i-1>=0)
            up=helper(i-1,j,grid,dp);
        if((j-1)>=0)
            left=helper(i,j-1,grid,dp);

        return dp[i][j]=grid[i][j]+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        return helper(r-1,c-1,grid,dp);
        
    }
};
// Tabulation Solution
// Time Complexity: O(r*c)
// Space Complexity: O(r*c)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=grid[i][j];
                else
                {
                    int up=INT_MAX,left=INT_MAX;
                    // moving up
                    if(i-1>=0)
                        up=dp[i-1][j];
                    if((j-1)>=0)
                        left=dp[i][j-1];

                   dp[i][j]=grid[i][j]+min(left,up);
                }
            }
        }
        return dp[r-1][c-1];
        
    }
};
// Space Optimized Tabulation Solution
// Time Complexity: O(r*c)
// Space Complexity: O(c)*2
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();
       vector<int>prev(c,0),curr(c,0);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0 && j==0)
                   curr[j]=grid[i][j];
                else
                {
                    int up=INT_MAX,left=INT_MAX;
                    // moving up
                    if(i-1>=0)
                        up=prev[j];
                    if((j-1)>=0)
                        left=curr[j-1];

                   curr[j]=grid[i][j]+min(left,up);
                }
            }
            prev=curr;
        }
        return prev[c-1];
        
    }
};