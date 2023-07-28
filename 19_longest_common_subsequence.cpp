#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i, int j, string s1, string s2)
    {
        if(i<0 || j<0)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s1[i]==s2[j])
            return dp[i][j] = 1+solve(i-1,j-1,s1,s2);
        return dp[i][j] = max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.length(),vector<int> (text2.length(),-1));
        return solve(text1.length()-1,text2.length()-1,text1,text2);
    }
};