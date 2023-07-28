#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    int solve(int prev, int idx, vector<int> &nums)
    {
        if(idx==nums.size())
            return 0;

        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];

        if(prev==-1 || nums[idx]>nums[prev])
            return max(1+solve(idx,idx+1,nums),solve(prev,idx+1,nums));
        return dp[idx][prev+1] = solve(prev,idx+1,nums);
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(-1,0,nums);
    }
};