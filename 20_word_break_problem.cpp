#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> dp;

    bool solve(int i, string s, vector<string>& wordDict)
    {
        if(i==s.length())
            return true;

        if(dp[i]!=-1)
            return dp[i];

        bool res = false;
        for(auto &word:wordDict)
        {
            int length = word.length();
            if(s.substr(i,length)==word)
                res = res || solve(i+length,s,wordDict);
        }
        return dp[i] = res ? 1:0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(),-1);
        return solve(0,s,wordDict);
    }
};