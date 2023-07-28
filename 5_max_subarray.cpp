#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currSum = nums[0];
//         int mxSum = nums[0];
//         for(int i=1;i<nums.size();i++)
//         {
//             currSum = max(currSum+nums[i],nums[i]);
//             mxSum = max(mxSum,currSum);
//         }
//         return mxSum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int mx = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(sum+nums[i]<nums[i])
                sum = nums[i];
            else
                sum += nums[i];
            if(sum>mx)
                mx = sum;
        }
        return mx;
    }
};