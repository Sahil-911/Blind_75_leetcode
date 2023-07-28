#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int low = 0, high = nums.size()-1;
//         int mini = nums[0];
//         while(low<=high)
//         {
//             if(nums[low]<nums[high])
//                 return min(mini,nums[low]);
//             int mid = (low+high)/2;
//             mini = min(mini,nums[mid]);
//             if(nums[low]<=nums[mid])
//                 low = mid+1;
//             else
//                 high = mid-1;
//         }
//         return mini;
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mini = 1e5;
        while(low<=high)
        {
            mini = min({nums[low],nums[high],mini});
            int mid = (low+high)>>1;
            mini = min(mini,nums[mid]);
            if(nums[mid]>nums[low])
                low = mid+1;
            else
                high = mid-1;
        }
        return mini;
    }
};