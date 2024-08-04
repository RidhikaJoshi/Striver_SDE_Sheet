#include<bits/stdc++.h>
using namespace std;
// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: Recursion Stack
class Solution
{
    public:
    int helper(int ind,int W,int wt[],int val[])
    {
        if(ind==0)
        {
            if(wt[0]<=W)
                return val[0];
            return 0;
        }
        // picking up the element
        int pick=INT_MIN,notpick=INT_MIN;
        if(wt[ind]<=W)
            pick=val[ind]+helper(ind-1,W-wt[ind],wt,val);
        // not picking up the currElemet
            notpick=helper(ind-1,W,wt,val);
        return max(pick,notpick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        return helper(n-1,W,wt,val);
        
    }
};
// Memoization Solution
// Time Complexity: O(n*W)
// Space Complexity: O(n*W)+Recursion Stack
class Solution
{
    public:
    int helper(int ind,int W,int wt[],int val[],vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(wt[0]<=W)
                return val[0];
            return 0;
        }
        if(dp[ind][W]!=-1)
            return dp[ind][W];
        // picking up the element
        int pick=INT_MIN,notpick=INT_MIN;
        if(wt[ind]<=W)
            pick=val[ind]+helper(ind-1,W-wt[ind],wt,val,dp);
        // not picking up the currElemet
            notpick=helper(ind-1,W,wt,val,dp);
        return dp[ind][W]=max(pick,notpick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return helper(n-1,W,wt,val,dp);
        
    }
};
// Tabulation Method
// Time Complexity: O(n*W)
// Space Complexity: O(n*W)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        //return helper(n-1,W,wt,val,dp);
        for(int i=wt[0];i<=W;i++)
            dp[0][i]=val[0];
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=W;target++)
            {
               int pick=INT_MIN,notpick=INT_MIN;
                if(wt[ind]<=target)
                    pick=val[ind]+dp[ind-1][target-wt[ind]];
                notpick=dp[ind-1][target];
                dp[ind][target]=max(pick,notpick); 
            }
        }
        return dp[n-1][W];
        
    }
};

//Space Optimized Tabulation Method
// Time Complexity: O(n*W)
// Space Complexity: O(W)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //vector<vector<int>>dp(n,vector<int>(W+1,0));
        //return helper(n-1,W,wt,val,dp);
        vector<int>prev(W+1,0),curr(W+1,0);
        for(int i=wt[0];i<=W;i++)
           prev[i]=val[0];
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=W;target++)
            {
               int pick=INT_MIN,notpick=INT_MIN;
                if(wt[ind]<=target)
                    pick=val[ind]+prev[target-wt[ind]];
                notpick=prev[target];
                curr[target]=max(pick,notpick); 
            }
            prev=curr;
        }
        return prev[W];
        
    }
};