#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(V*E).
// Auxiliary Space: O(V).
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       vector<int>dist(V,1e8);
       dist[S]=0;
       for(int i=0;i<V-1;i++)
       {
           for(int j=0;j<edges.size();j++)
           {
               int u=edges[j][0];
               int v=edges[j][1];
               int wt=edges[j][2];
               // if the dist[u] ==1e8
               // then it should not go inside the if 
               // beacuse if wt is neagtive then dist will be updated
               if(dist[u]!=1e8 && dist[v]>dist[u]+wt)
               {
                   dist[v]=dist[u]+wt;
               }
               
           }
       }
       for(int i=0;i<edges.size();i++)
       {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            if(dist[u]!=1e8 && dist[v]>dist[u]+wt)
            {
                return {-1};
                // negative cycle exists
                // return -1;
            }
       }
       return dist;
    }
};