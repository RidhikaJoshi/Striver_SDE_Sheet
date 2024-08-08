#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,vector<vector<int>>&vis,int pr,int pc,int color)
    {
        vis[i][j]=1;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,-1,0,1};
        for(int k=0;k<4;k++)
        {
            int nr=i+delr[k];
            int nc=j+delc[k];
            if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size())
            {
                if(image[nr][nc]==image[pr][pc] && vis[nr][nc]==0)
                {
                    dfs(nr,nc,image,vis,i,j,color);
                    image[nr][nc]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int r=image.size();
        int c=image[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        dfs(sr,sc,image,vis,sr,sc,color);
        image[sr][sc]=color;   
        return image;     
    }
};