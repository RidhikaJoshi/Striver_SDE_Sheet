#include<bits/stdc++.h>
using namespace std;
// Recursive approach
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
  public:
    void helper(int ind,vector<int>arr,int n,vector<int>&res,int sum)
    {
        if(ind==n)
        {
            res.push_back(sum);
            return;
        }
        // picking the curr element
        helper(ind+1,arr,n,res,sum+arr[ind]);
        // not picking the curr element
        helper(ind+1,arr,n,res,sum);
        
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int>res;
        helper(0,arr,n,res,0);
        return res;
      
    }
};