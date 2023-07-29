#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> topoSort(vector<vector<int>> &adj)
    {
        vector<int> inDegree(adj.size(),0);
        vector<int> sorted;
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                inDegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &i: adj[node])
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                {
                    sorted.push_back(i);
                    q.push(i);
                }
            }
        }
        return sorted;

    }

    string finalOrder(string dict[],int n, int k)
    {
        vector<vector<int>> adj(k);
        for(int i=0;i<n-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int j = 0;
            while(j<min(s1.length(),s2.length()) && s1[j]==s2[j])
                j++;
            if(j<min(s1.length(),s2.length()))
                adj[s1[j]-'a'].push_back(s2[j]-'a');
        }
        vector<int> store = topoSort(adj);
        string ans;
        for(int i=0;i<store.size();i++)
            ans.push_back(store[i]+'a');
        return ans;

    }
};