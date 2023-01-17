#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dp[26][26][101];
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    double solve(int n, int k, int r, int c){
        if(r<0 || r>=n || c<0 || c>=n)
            return 0;
        if(k == 0)  return 1;

        if(dp[r][c][k]) return dp[r][c][k];

        double total = 0;
        for(int x = 0; x<8; x++)
            total += solve(n, k-1, r+dx[x], c+dy[x]);

        return dp[r][c][k] = total/8; 
    }

    double knightProbability(int n, int k, int row, int column) {
        return solve(n, k, row, column);
    }
};