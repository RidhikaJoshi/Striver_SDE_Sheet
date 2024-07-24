#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool check(char a,char b)
    {
        if(a=='(' && b==')')
            return true;
        if(a=='{' && b=='}')
            return true;
        if(a=='[' && b==']')
            return true;
        return false;
    }
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       stack<char>st;
       for(int i=0;i<x.length();i++)
       {
           if(x[i]=='(' || x[i]=='{' || x[i]=='[')
                st.push(x[i]);
            else
            {
                if(st.size()==0)
                    return false;
                if(!check(st.top(),x[i]))
                    return false;
                else
                    st.pop();
            }
       }
       if(st.size()!=0)
        return false;
       return true;
    }

};