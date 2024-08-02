#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N+E)
// Space Complexity: O(N+E) + O(N) = O(N)*2
class Solution {
  public:
    bool bfs(int srcNode,vector<int> adj[],
    vector<int>&vis)
    {
        vis[srcNode]=1;
        queue<pair<int,int>>q;
        q.push({srcNode,-1});
        while(q.size()!=0)
        {
            int currNode=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode:adj[currNode])
            {
                if(vis[adjNode]==0)
                {
                    vis[adjNode]=1;
                    q.push({adjNode,currNode});
                }
                else if(parent!=adjNode)
                {
                   // cout << parent << "  " << currNode << endl;
                    return true;
                }
                    
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       for(int i=0;i<V;i++)
       {
           if(vis[i]==0)
           {
               if(bfs(i,adj,vis))
                return true;
           }
       }
       return false;
    }
};