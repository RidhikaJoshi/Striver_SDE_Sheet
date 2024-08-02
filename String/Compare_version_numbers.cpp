#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int i=0,j=0;
        while(i<version1.length() && j<version2.length())
        {
            string s1,s2;
            while(i<version1.length() && version1[i]!='.')
            {
                s1+=version1[i];
                i++;
            }
            
            i++;
            while(j<version2.length() && version2[j]!='.')
            {
                s2+=version2[j];
                j++;
            }
            j++;
            //cout << stoi(s1)  << "  " << stoi(s2) << endl;
            if(stoi(s1)>stoi(s2))
                return 1;
            else if(stoi(s1)<stoi(s2))
                return -1;

        }
         //cout << i  << "  " << j << endl;
        if(i>version1.length() && j>version2.length())
            return 0;
         while(i<version1.length())
            {
                if(version1[i]!='0' && version1[i]!='.')
                    return 1;
                i++;
            }
        while(j<version2.length())
            {
                if(version2[j]!='0' && version2[j]!='.')
                    return -1;
                j++;
            }
         return 0;
        
        
        
    }
};