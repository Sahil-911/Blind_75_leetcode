#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        int i=0, j=height.size()-1;
        while(i<j)
        {
            int width = j-i;
            int hei = min(height[i],height[j]);
            mx = max(mx,hei*width);
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return mx;
    }
};