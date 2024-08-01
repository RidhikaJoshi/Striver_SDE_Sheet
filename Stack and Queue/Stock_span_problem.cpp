#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)*2
// Space Complexity: O(n)
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
      vector<int>res;
      stack<int>st;
      for(int i=0;i<n;i++)
      {
            if(st.size()==0)
                res.push_back(-1);
            else if( price[st.top()]>price[i])
                res.push_back(st.top());
            else
            {
                while(st.size()!=0 && price[st.top()]<=price[i])
                    st.pop();
                if(st.size()==0)
                    res.push_back(-1);
                else
                    res.push_back(st.top());
            }
            st.push(i);
      }
      for(int i=0;i<res.size();i++)
      {
          res[i]=i-res[i];
      }
      return res;
      
    }
};