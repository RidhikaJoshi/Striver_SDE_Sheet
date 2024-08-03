#include<bits/stdc++.h>
using namespace std;
// Applying TopoSort Technique to detect cycle in a directed graph
// Time Complexity: O(V+E)
// Space Complexity: O(V)*2
// queue and indeg vector
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>indeg(V);
       for(int i=0;i<V;i++)
       {
           for(auto it:adj[i])
           {
               indeg[it]++;
           }
       }
       queue<int>q;
       for(int i=0;i<V;i++)
       {
           if(indeg[i]==0)
            q.push(i);
       }
       int countNodes=0;
       while(q.size()!=0)
       {
           int node=q.front();
           q.pop();
           countNodes++;
           for(auto it:adj[node])
           {
               indeg[it]--;
               if(indeg[it]==0)
                    q.push(it);
           }
       }
       if(countNodes==V)
            return false;
        return true;
    }
};