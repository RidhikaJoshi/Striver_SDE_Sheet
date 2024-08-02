#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N+E)
// Space Complexity: O(N) + O(N) = O(N)
class Solution
{
	public:
	void dfs(int src,vector<int>adj[],vector<int>&vis,stack<int>&st)
	{
	    vis[src]=1;
	    for(auto it:adj[src])
	    {
	        if(vis[it]==0)
	            dfs(it,adj,vis,st);
	    }
	    st.push(src);
	    return;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int>res;
	    while(st.size()!=0)
	    {
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};