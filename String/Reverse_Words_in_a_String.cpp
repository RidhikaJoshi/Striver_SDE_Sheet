#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string k="",res="";
        for(int i=0;i<S.length();i++)
        {
            if(S[i]!='.')
                k+=S[i];
            else
            {
                res=k+"."+res;
                k="";
            }
                
        }
        if(k!="")
            res=k+"."+res;
        res=res.substr(0,res.size()-1);
        return res;
    } 
};