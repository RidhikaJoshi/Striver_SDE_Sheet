#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(V+E)
// Space Complexity: O(V)
class Solution {
public:
    bool bfs(int srcNode,vector<int>adj[],vector<int>&color)
    {
        color[srcNode]=0;
        queue<int>q;
        q.push(srcNode);
        while(q.size()!=0)
        {
            int currNode=q.front();
            q.pop();
            for(auto it:adj[currNode])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[currNode];
                    q.push(it);
                }
                else if(color[it]==color[currNode])
                    return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(bfs(i,adj,color)==false)
	                return false;
	        }
	    }
	    return true;
	}

};