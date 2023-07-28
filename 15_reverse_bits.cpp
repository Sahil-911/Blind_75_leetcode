#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x=0;
        for(int i=0;i<32;i++)
        {
            uint32_t temp = (n>>i)&1;
            x = x | (temp<<(31-i));
        }
        return x;
    }
};