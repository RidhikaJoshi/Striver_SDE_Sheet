#include<bits/stdc++.h>
using namespace std;
// Recursive Solution
// Time Complexity: O(V+E
// Sapce Complexity: O(V)*2 + recursive stack space
class Solution {
  public:
    bool dfs(int srcNode,vector<int>adj[],vector<int>&vis,vector<int>&pathVis)
    {
        vis[srcNode]=1;
        pathVis[srcNode]=1;
        for(auto it:adj[srcNode])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,pathVis))
                    return true;
            }
            else if(pathVis[it]==1)
                return true;
        }
        pathVis[srcNode]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathVis))
                    return true;
            }
        }
        return false;
      
    }
};