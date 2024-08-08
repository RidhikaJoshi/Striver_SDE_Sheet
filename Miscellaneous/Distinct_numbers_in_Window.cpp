#include<bits/stdc++.h>
using namespace std;
// Distinct numbers in Window
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector <int>res;
       unordered_map<int,int>m;
       for(int i=0;i<k;i++)
       {
           m[A[i]]++;
       }
         res.push_back(m.size());
       for(int i=1;i<=n-k;i++)
       {
           m[A[i-1]]--;
           if(m[A[i-1]]==0)
                m.erase(A[i-1]);
            m[A[i+k-1]]++;
            
            res.push_back(m.size());
       }
       return res;
    }
};