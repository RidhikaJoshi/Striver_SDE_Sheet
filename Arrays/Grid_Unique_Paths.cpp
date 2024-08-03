#include<bits/stdc++.h>
using namespace std;
// Recursive Solution
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)
class Solution {
public:
    int helper(int r,int c)
    {
        if(r==0 && c==0)
            return 1;
        int up=0,left=0;
        // moving up
        if(r-1>=0)
            up=helper(r-1,c);
        // moving left
        if(c-1>=0)
            left=helper(r,c-1);
        return left+up;
    }
    int uniquePaths(int m, int n)
    {
        return helper(m-1,n-1);
        
    }
};
// Memoization Solution
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)+O(m+n)
class Solution {
public:
    int helper(int r,int c,vector<vector<int>>&dp)
    {
        if(r==0 && c==0)
            return 1;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int up=0,left=0;
        // moving up
        if(r-1>=0)
            up=helper(r-1,c,dp);
        // moving left
        if(c-1>=0)
            left=helper(r,c-1,dp);
        return dp[r][c]=(left+up);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
        
    }
};
// Tabulation Solution
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
int uniquePaths(int m, int n)
    {
        vector<vector<int>>dp(m,vector<int>(n,0));
        //return helper(m-1,n-1,dp);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                      dp[0][0]=1;
                else
                {
                    int up=0,left=0;
                    // moving up
                    if((i-1)>=0)
                        up=dp[i-1][j];
                    // moving left
                    if((j-1)>=0)
                        left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};
// Space Optimized Tabulation Solution
// Time Complexity: O(m*n)
// Space Complexity: O(n)*2
class Solution {
public:
int uniquePaths(int m, int n)
    {
       vector<int>prev(n,0),curr(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                     curr[0]=1;
                else
                {
                    int up=0,left=0;
                    // moving up
                    if((i-1)>=0)
                        up=prev[j];
                    // moving left
                    if((j-1)>=0)
                        left=curr[j-1];
                    curr[j]=left+up;
                }
            }
            prev=curr;
        }
        return prev[n-1];
        
    }
};