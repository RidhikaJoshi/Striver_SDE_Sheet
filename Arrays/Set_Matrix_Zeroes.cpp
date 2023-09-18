/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/
#include <bits/stdc++.h>
using namespace std;

// Naive Solution
// Time=O(m*n)*2
// Space=O(m+n)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> r, c;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (r.find(i) != r.end() || c.find(j) != c.end())
                    matrix[i][j] = 0;
            }
        }
    }
};