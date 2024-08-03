#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(n^2)+O(n)
// Space Complexity: O(n)*2
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat)
    {
        int numberOfPeople=mat.size();
        vector<int>indeg(numberOfPeople,0),outdeg(numberOfPeople,0);
        for(int i=0;i<numberOfPeople;i++)
        {
            for(int j=0;j<numberOfPeople;j++)
            {
                if(mat[i][j]==1)
                {
                    indeg[j]++;
                    outdeg[i]++;
                }
            }
        }
        for(int i=0;i<numberOfPeople;i++)
        {
            if(indeg[i]==numberOfPeople-1 && outdeg[i]==0)
                return i;
        }
        return -1;
    }
};
// Time Complexity: O(n)*2
// Space Complexity: O(1)
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int numberOfPeople=mat.size();
       int top=0,bottom=numberOfPeople-1;
       while(top<bottom)
       {
           if(mat[top][bottom]==1)
                top++;
            else if(mat[bottom][top]==1)
                bottom--;
            else
            {
                top++;
                bottom--;
            }
       }
       // << top <<  " " << bottom << endl;;
       if(top!=bottom)
        return -1;
        // entire row of the top/bottom shoulde 
        // be zero for top/bottom to be a celerbrity
        for(int i=0;i<numberOfPeople;i++)
        {
            if(i!=top)
            {
                if(mat[top][i]!=0 || mat[i][top]!=1)
                    return -1;
            }
        }
        return top;
        
    }
};