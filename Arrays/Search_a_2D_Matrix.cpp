#include<bits/stdc++.h>
using namespace std;
// Naive Approach
// Time Complexity: O(n*m)
// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==target)
                    return true;
            }
        }
        return false;
        
    }
};
// Optimized Approach
// Time Complexity: O(m+logn)
// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][n-1])
            {
                int low=0,high=n-1;
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    if(matrix[i][mid]==target)
                        return true;
                    else if(matrix[i][mid]<target)
                        low=mid+1;
                    else
                            high=mid-1;
                }
            }
        }
        return false;
    }
};
// Time Complexity: O(m+n)
// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int i=0,j=0;
        if(target<matrix[0][0] || target>matrix[row-1][col-1])
            return false;
        while(i<row && j<col)
        {
            if(target==matrix[i][j])
                return true;
            if(target>matrix[i][j])
            {
                if((i+1)<row && target>=matrix[i+1][j])
                    i+=1;
                else if((j+1)<col && target>=matrix[i][j+1])
                    j+=1;
                else
                    return false;
            }
          
        }
        return false;
    }
};