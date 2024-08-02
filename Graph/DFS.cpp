#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N+E)
// Space Complexity: O(N+E) + O(N) + O(N) = O(N)
class Solution {
  public:
    void dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&res)
    {
        vis[src]=1;
        res.push_back(src);
        for(auto it:adj[src])
        {
            if(vis[it]==0)
                dfs(it,adj,vis,res);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>res;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++) // graph may be disconnected graph
        // using this approach we can visit all the nodes of the graph
        {
            if(vis[i]==0)
                dfs(i,adj,vis,res);
        }
        return res;
    }
};
// Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}