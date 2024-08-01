#include<bits/stdc++.h>
using namespace std;
// Recursive approach
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    void helper(int ind,vector<int>nums,int n,vector<int>&r,set<vector<int>>&st)
    {
        if(ind==n)
        {
            vector<int>temp=r;
            // for sorting the current values of r
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        // picking up the element
        r.push_back(nums[ind]);
        helper(ind+1,nums,n,r,st);
        r.pop_back();
        helper(ind+1,nums,n,r,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>>res;
        vector<int>r;
        int n=nums.size();
        set<vector<int>>st;
        helper(0,nums,n,r,st);
        for(auto it:st)
        {
            res.push_back(it);
        }
        return res;
        
    }
};