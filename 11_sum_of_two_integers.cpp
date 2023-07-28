#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        for(int i=0;i<32;i++)
        {
            int temp = ((a>>i) & 1)^((b>>i) & 1)^carry;
            temp = temp<<i;
            carry = ((a>>i) & 1) & ((b>>i) & 1) | ((a>>i) & 1) & carry | ((b>>i) & 1) & carry;
            ans = ans | temp;
        }
        return ans;
    }
};