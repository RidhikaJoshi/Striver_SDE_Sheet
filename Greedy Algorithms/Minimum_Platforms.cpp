#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(nlogn)*2
// Space Complexity: O(1)
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int res=0;
        int i=0,j=0,count=0;
        while(i<n )
        {
           if(arr[i]<=dep[j])
            {
                i++;
                count++;
            }
           else
            {
                j++;
                count--;
            }
            res=max(res,count);
        }
        return res;
    }
};