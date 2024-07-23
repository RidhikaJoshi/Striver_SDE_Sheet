#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int>res;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
                res.push_back(-1);
            else if(st.top()<a[i])
                res.push_back(st.top());
            else
            {
                while(st.size()!=0 && st.top()>=a[i])
                    st.pop();
                if(st.size()==0)
                res.push_back(-1);
                else
                res.push_back(st.top());
            }
            st.push(a[i]);
        }
        return res;
    }
};