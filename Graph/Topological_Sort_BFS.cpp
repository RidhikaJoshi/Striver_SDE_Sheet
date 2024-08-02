#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N+E)
// Space Complexity: O(N) + O(N) = O(N)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        // adj matrix already given
	    vector<int>topoSort;
	    vector<int>indeg(V,0);
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
	   while(q.size()!=0)
	   {
	       int currNode=q.front();
	       q.pop();
	       topoSort.push_back(currNode);
	       for(auto it:adj[currNode])
	       {
	           indeg[it]--;
	           if(indeg[it]==0)
	            q.push(it);
	       }
	   }
	   return topoSort;
	   
	}
};