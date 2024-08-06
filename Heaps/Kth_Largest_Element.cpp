#include<bits/stdc++.h>
using namespace std;

// Naive Solution
// Using sorting technique
// Time Complexity: O(NlogN)
// Space Complexity: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.rbegin(),nums.rend());
        return nums[k-1];
        
    }
};

// Efficient Solution
// Using priority_queue
// Time Complexity: O(NlogK)
// Space Complexity: O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
       // using priority_queue
       priority_queue<int,vector<int>,greater<int>>pq;
       for(int i=0;i<nums.size();i++)
       {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
       }
        return pq.top();
    }
};