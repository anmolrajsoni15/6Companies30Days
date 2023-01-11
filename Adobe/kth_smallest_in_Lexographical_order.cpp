#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        long long N = n;
        long long K = k;

        long long ans = 1;
        for(K = K-1; K>0; ){
            int range = 0;
            for(long long i = ans, j = ans+1; i<=N; i*=10, j*=10){
                range += (min(N+1, j)-i);
            }

            if(K >= range){
                ans++;
                K -= range;
            }
            else{
                ans *= 10;
                K--;
            }
        }

        return ans;
    }
};