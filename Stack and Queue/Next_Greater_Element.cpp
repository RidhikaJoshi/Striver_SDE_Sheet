#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
      vector<long long>res;
      stack<long long>st;
      for(int i=arr.size()-1;i>=0;i--)
      {
            if(st.size()==0)
                res.push_back(-1);
            else if(st.top()>arr[i])
                res.push_back(st.top());
            else
            {
               while(st.size()!=0 && st.top()<=arr[i])
                    st.pop();
                    
                if(st.size()==0)
                    res.push_back(-1);
                else if(st.top()>arr[i])
                    res.push_back(st.top());
            }
            st.push(arr[i]);
      }
      reverse(res.begin(),res.end());
      return res;
    }
};