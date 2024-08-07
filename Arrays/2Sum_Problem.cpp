#include<bits/stdc++.h>
using namespace std;

// Naive Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {};
        
    }
};
// Optimised Solution
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                return {m[target-nums[i]],i};
            }
            m[nums[i]]=i;
        }
        return {};
        
    }
};