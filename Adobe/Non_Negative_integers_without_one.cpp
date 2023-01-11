#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        vector<int> dpZeros(32), dpOnes(32), dp(32);
        dpZeros[0] = dp[0] = 1;

        for(int i = 1; i<32; i++){
            dpOnes[i] = dpZeros[i-1];
            dpZeros[i] = dpZeros[i-1]+dpOnes[i-1];
            dp[i] = dpZeros[i]+dpOnes[i];
        }

        int ans = 0;
        int prevBit = -1;
        for(int i = 30; i>=0; i--){
            int bit = (n>>i)&1;
            if(bit == 1){
                ans += dp[i];
                if(prevBit == 1)
                    return ans;
            }
            prevBit = bit;
        }

        return ans+1;
    }
};