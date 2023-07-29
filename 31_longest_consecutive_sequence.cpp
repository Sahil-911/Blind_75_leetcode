#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for(auto &n:nums)
            us.insert(n);
        int mxLen = 0;
        for(auto &n:nums)
        {
            if(us.find(n-1)==us.end())
            {
                int length = 1;
                while(us.find(n+length)!=us.end())
                    length++;
                mxLen = max(mxLen,length);
            }
        }
        return mxLen;
    }
};