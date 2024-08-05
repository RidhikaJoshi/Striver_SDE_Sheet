#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)
// Space Complexity: O(N)
// Greedy Solution
class Solution{
public:
    vector<int> minPartition(int N)
    {
       vector<int>coins={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
       vector<int>ans;
       for(int i=coins.size()-1;i>=0;i--)
       {
           int r=N/coins[i];
           N=N-(r*coins[i]);
           ans.insert(ans.end(), r, coins[i]);
       }
       return ans;
    }
};