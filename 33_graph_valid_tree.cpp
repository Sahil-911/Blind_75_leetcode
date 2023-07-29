#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int prev, int node, vector<vector<int>> &adj, unordered_set<int> &vis)
    {
        vis.insert(node);
        for(auto &i:adj[node])
        {
            if(i!=prev)
                dfs(node,i,adj,vis);
        }
    }

    bool validTree(int n, vector<vector<int>> &edges)
    {
        if(edges.size()!=n-1)
            return false;
        
        unordered_set<int> vis;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back(adj[i][1]);
        dfs(-1,0,adj,vis);
        return vis.size()==n;
    }
};