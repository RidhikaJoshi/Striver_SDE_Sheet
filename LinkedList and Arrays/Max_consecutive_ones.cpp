#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N)
// Space Complexity : O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int count=0,mx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            else
            {
                mx=max(mx,count);
                count=0;
            }
        }
        mx=max(mx,count);
        return mx;
    }
};