#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(nlogn)*2
// Space Complexity: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int contentChildren=0;
        int i=0,j=0;
        while(i<g.size() && j<s.size())
        {
            if(s[j]>=g[i])
            {
                i++;
                j++;
                contentChildren++;
            }
            else
                j++;
        }
        return contentChildren;
        
    }
};