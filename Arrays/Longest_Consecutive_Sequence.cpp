#include<bits/stdc++.h>
using namespace std;
// Optimised Solution
// Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
// Reason: O(N) for putting all the elements into the set data structure. 
// After that for every starting element, we are finding the consecutive elements. 
// Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
// Space Complexity: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        int mx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                int count=0,x=nums[i];
                while(st.find(x+count)!=st.end())
                {
                    count++;
                }
                 mx=max(mx,count);
            }
           
        }
        return mx;
        
    }
};