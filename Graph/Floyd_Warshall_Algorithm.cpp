#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix)
	{
	    int rows=matrix.size();
	    int col=matrix[0].size();
	    for(int i=0;i<rows;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(matrix[i][j]==-1)
	                matrix[i][j]=1e5;
	         }
	    }
	    // Applying floyd warshall algorithm
	    for(int k=0;k<rows;k++)
	    {
	        for(int i=0;i<rows;i++)
	        {
	            for(int j=0;j<rows;j++)
	            {
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<rows;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(matrix[i][j]==1e5)
	                matrix[i][j]=-1;
	         }
	    }
	    
	}
};