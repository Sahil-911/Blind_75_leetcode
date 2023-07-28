#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> dp;
    int solve(int i, vector<int>& nums)
    {
        if(i>=nums.size())
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        return dp[i] = max(nums[i]+solve(i+2,nums),solve(i+1,nums));
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return max(solve(0,nums),solve(1,nums));
    }
};