#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int myAtoi(string s)
    {
        string res="";
       int flag=1;
        int i=0;
        while(s[i]==' ')
            i++;
       
        if(s[i]=='-')
        {
            i++;
            flag=-1;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        while(s[i]=='0')
            i++;
       
        for(int j=i;j<s.length();j++)
        {
            if(int(s[j])>=48 && int(s[j])<=57)
            {
                res+=s[j];
            }
            else
                break;
        }
        if(res.length()>10)
        {
            if(flag==-1)
                return INT_MIN;
            else
                return INT_MAX;
        }
        if(res.length()==10)
        {
            long long ans=stoll(res);
            ans=ans*flag;
            if(ans<INT_MIN)
                 return INT_MIN;
            else if(ans>INT_MAX)
                return INT_MAX;
            return ans;
        }
        if(res=="")
            return 0;
        int ans=stoi(res)*flag;
        return ans;
        
    }
};