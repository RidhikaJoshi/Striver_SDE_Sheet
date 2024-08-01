#include<bits/stdc++.h>
using namespace std;
// 39. Combination Sum
// Medium
// Time Complexity=O(2^n)
// Space Complexity=O(n)
class Solution {
public:
    void helper(int ind,vector<int>candidates,int target,vector<int>&r,vector<vector<int>>&res,int sum)
    {
        if(sum==target)
        {
            res.push_back(r);
            return;
        }
        if(ind==candidates.size())
        {
           return;
        }
        if(sum+candidates[ind]<=target)
        {
            r.push_back(candidates[ind]);
            helper(ind,candidates,target,r,res,sum+candidates[ind]);
            r.pop_back();
        }
        // not picking the curr index element
        helper(ind+1,candidates,target,r,res,sum);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int>r;
        vector<vector<int>>res;
        helper(0,candidates,target,r,res,0);
        return res;
    }
};