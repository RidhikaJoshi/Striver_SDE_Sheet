#include<bits/stdc++.h>
using namespace std;
// Brute Force Solution
// Time Complexity: O(n*m)
// Space Complexity: O(1)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        // brute force solution
        for(int i=0;i<haystack.size();i++)
        {
            if(haystack[i]==needle[0])
            {
                int j=0,k=i;
                while(k<haystack.size() && j<needle.size())
                {
                    if(haystack[k]!=needle[j])
                    {
                        break;
                    }
                    k++;j++;
                }
                if(j==needle.length())
                    return i;

            }
        }
        return -1;
        
    }
};

// Optimized Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int m=haystack.length();
        int n=needle.length();
        for(int i=0;i<=m-n;i++)
        {
            if(haystack[i]==needle[0])
            {
                string k=haystack.substr(i,n);
                if(k==needle)
                    return i;
            }
        }
        return -1;
        
    }
};