#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i-1]==nums[i])
                continue;
            int target = -1*nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]>target)
                    k--;
                else if(nums[j]+nums[k]<target)
                    j++;
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j-1]==nums[j])
                        j++;
                    while(j<k && nums[k+1]==nums[k])
                        k--;
                }
            }
        }
        return ans;
    }
};