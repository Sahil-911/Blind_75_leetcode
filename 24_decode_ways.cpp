#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int i, string s,vector<int> &dp)
    {
        if(dp[i]>-1)
            return dp[i];
        
        if(s[i]=='0')
            return dp[i]=0;

        int res = solve(i+1,s,dp);
        if(i+1<s.length() && (s[i]=='1' || (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6')))
            res += solve(i+2,s,dp);

        return dp[i] = res;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        dp[s.length()]=1;
        return solve(0,s,dp);
    }
};