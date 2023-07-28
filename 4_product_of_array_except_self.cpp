#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> leftpro(nums.size());
//         vector<int> rightpro(nums.size());
//         vector<int> ans(nums.size());
//         leftpro[0]=1;
//         for(int i=1;i<nums.size();i++)
//             leftpro[i]=leftpro[i-1]*nums[i-1];
//         rightpro[nums.size()-1]=1;
//         for(int i=nums.size()-2;i>=0;i--)
//             rightpro[i]=rightpro[i+1]*nums[i+1];
//         for(int i=0;i<nums.size();i++)
//             ans[i]=leftpro[i]*rightpro[i];
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0]=1;
        for(int i=1;i<nums.size();i++)
            ans[i]=ans[i-1]*nums[i-1];
        int right=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]=ans[i]*right;
            right=right*nums[i];
        }
        return ans;
    }
};