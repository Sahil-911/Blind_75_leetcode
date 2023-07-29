#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<vector<int>>> flow(m,vector<vector<int>>(n,vector<int>(2,0)));
        queue<vector<int>> q;
        for(int i=0;i<m;i++)
        {
            q.push({i,0,0});
            q.push({i,n-1,1});
        } 
        for(int j=0;j<n;j++)
        {
            q.push({0,j,0});
            q.push({m-1,j,1});
        }
        while(!q.empty())
        {
            int row = q.front()[0];
            int col = q.front()[1];
            int from = q.front()[2];
            q.pop();
            flow[row][col][from]++;
            if(row-1>=0 && heights[row-1][col]>=heights[row][col] && !flow[row-1][col][from])
                q.push({row-1,col,from});
            if(row+1<m && heights[row+1][col]>=heights[row][col] && !flow[row+1][col][from])
                q.push({row+1,col,from});
            if(col-1>=0 && heights[row][col-1]>=heights[row][col] && !flow[row][col-1][from])
                q.push({row,col-1,from});
            if(col+1<n && heights[row][col+1]>=heights[row][col] && !flow[row][col+1][from])
                q.push({row,col+1,from});
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(flow[i][j][0] && flow[i][j][1])
                    ans.push_back({i,j});
        return ans;
    }
};