#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. 
//In the case of connected components of a graph, it will take another O(N) time.
// Space Complexity: O(N+E) + O(N) = O(N)*2
class Solution {
  public:
    bool dfs(int src,vector<int>adj[],vector<int>&vis,int parent)
    {
        vis[src]=1;
        for(auto it:adj[src])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,src))
                    return true;
            }
            else if(parent!=it)
                return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
       vector<int>vis(V,0);
       for(int i=0;i<V;i++)
       {
           if(vis[i]==0)
           {
               if(dfs(i,adj,vis,-1))
                    return true;
           }
       }
       return false;
    }
};