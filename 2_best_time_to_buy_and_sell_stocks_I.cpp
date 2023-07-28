#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>buy)
                mx = max(mx,prices[i]-buy);
            else if(prices[i]<buy)
                buy = prices[i];
        }
        return mx;
    }
};