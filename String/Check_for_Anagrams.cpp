#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(nlogn)+O(n)
// Space Complexity: O(1)
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        if(a.length()!=b.length())
            return false;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;

        // Your code here
    }
};
// Time Complexity: O(n)
// Space Complexity: O(26)*2
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        if(a.length()!=b.length())
            return false;
        unordered_map<char,int>m1,m2;
        for(int i=0;i<a.length();i++)
        {
            m1[a[i]]++;
            m2[b[i]]++;
        }
        for(auto it:m1)
        {
            if(m2[it.first]!=it.second)
                return false;
        }
        return true;

       
    }
};