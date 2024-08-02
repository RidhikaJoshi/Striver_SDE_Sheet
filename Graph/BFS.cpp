#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N+E)
// Space Complexity: O(N+E) + O(N) + O(N) = O(N)*3
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>res;
        queue<int>q;
        q.push(0);// starting node as stated
        vector<int>vis(V,0);
        vis[0]=1;
        while(q.size()!=0)
        {
            int currNode=q.front();
            q.pop();
            res.push_back(currNode);
            for(auto it:adj[currNode])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return res;
      
    }
};
//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends