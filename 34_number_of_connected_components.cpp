#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[node] = true;
        for(auto &i:adj[node])
        {
            if(!vis[i])
                dfs(i,adj,vis);
        }
    }

    int noOfConnetedComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back(edges[i][1]);
        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};