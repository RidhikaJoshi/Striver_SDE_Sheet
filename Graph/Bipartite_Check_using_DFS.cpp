#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(V+E)
// Space Complexity: O(V)+ Recursion call Stack
class Solution {
public:
    bool dfs(int srcNode,vector<int>adj[],vector<int>&color,int p)
    {
        if(p==-1)
            color[srcNode]=0;
        else
            color[srcNode]=!color[p];
        for(auto it:adj[srcNode])
        {
            if(color[it]==-1)
            {
                if(dfs(it,adj,color,srcNode)==false)
                    return false;
            }
            else if(color[it]==color[srcNode])
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            
	            if(dfs(i,adj,color,-1)==false)
	                return false;
	        }
	    }
	    return true;
	}

};