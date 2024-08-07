#include<bits/stdc++.h>
using namespace std;
// Better Solution
// Time Complexity: O(N+M)
// Space Complexity: O(1)
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int i=0,j=0;
        int res=0;
        while(i<arr1.size() && j<arr2.size())
        {
            if(arr1[i]<arr2[j])
            {
                res=arr1[i];
                i++;
            }
            else if(arr1[i]>=arr2[j])
            {
                res=arr2[j];
                j++;
            }
            k--;
            if(k==0)
                return res;
        }
        while(i<arr1.size())
        {
            res=arr1[i];
            i++;
            k--;
            if(k==0)
                return res;
        }
        while(j<arr2.size())
        {
            res=arr2[j];
            j++;
            k--;
            if(k==0)
                return res;
        }
        return -1;
    }
};