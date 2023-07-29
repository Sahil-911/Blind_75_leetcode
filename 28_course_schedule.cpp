#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto &i:prerequisites)
        {
            int course = i[0];
            int precourse = i[1];
            adj[precourse].push_back(course);
            inDegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &i:adj[node])
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                    q.push(i);
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]!=0)
                return false;
        }
        return true;
    }
};