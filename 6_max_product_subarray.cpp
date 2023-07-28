#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(),nums.end());
        int mini = 1;
        int mx = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                mini = 1;
                mx = 1;
                continue;
            }
            int temp = mini*nums[i];
            mini = min({nums[i]*mx,nums[i]*mini,nums[i]});
            mx = max({nums[i]*mx,temp,nums[i]});
            ans = max(ans,mx);
        }
        return ans;
    }
};