#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& arr)
    {
        int i=1,j=1;
        while(j<arr.size())
        {
            if(arr[j]==arr[i-1])
                j++;
            else
            {
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
        }
        return i;
        
    }
};