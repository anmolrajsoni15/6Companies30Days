#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
class Solution1 {
public:
    vector<int> ans;
    int mini = 0;

    void solve(int n, int numArrows, vector<int> &aliceArrows, int sum, vector<int> &bob){
        //base case
        if(n == -1 || numArrows <= 0){
            if(sum > mini){
                mini = sum;
                if(numArrows > 0){
                    bob[0] += numArrows;
                }
                ans = bob;
            }
            return;
        }

        //take
        int req = aliceArrows[n]+1;
        if(req <= numArrows){
            bob[n] = req;
            solve(n-1, numArrows-req, aliceArrows, sum+n, bob);
            //backtrack the value to its inital value after returning
            bob[n] = 0;
        }

        //not take
        solve(n-1, numArrows, aliceArrows, sum, bob);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12, 0);
        solve(11, numArrows, aliceArrows, 0, bob);
        return ans;
    }
};

//Approach 2: Using dp
class Solution2 {
public:
    int solve(int ind, int total, vector<int> &aliceArrows, vector<vector<int>> &dp){
        //base case
        if(ind <= 0)
            return 0;

        //if element already present in dp array
        if(dp[ind][total] != -1)
            return dp[ind][total];

        //take
        int take = 0;
        if(aliceArrows[ind] < total)
            take = ind+solve(ind-1, total-aliceArrows[ind]-1, aliceArrows, dp);

        //not take
        int notTake = solve(ind-1, total, aliceArrows, dp);

        return dp[ind][total] = max(take, notTake);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12, 0);
        vector<vector<int>> dp(12, vector<int>(numArrows+1, -1));

        int ans = solve(11, numArrows, aliceArrows, dp);
        int sum = 0;
        for(int i = 12, j = numArrows; i>0 && ans>0; i--){
            if(ans == dp[i-1][j])   continue;
            else{
                bob[i] = aliceArrows[i]+1;
                ans -= i;
                j -= (aliceArrows[i]+1);
                sum += (aliceArrows[i]+1);
            }
        }

        if(sum < numArrows)
            bob[0] = numArrows-sum;

        return bob;
    }
};

//Approach 3: Using Bitmask
class Solution3 {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = (1<<12);
        int maxScore = 0;
        vector<int> ans;

        for(int mask = 1; mask<n; mask++){
            int rem = numArrows, score = 0;
            vector<int> bob(12, 0);

            //checking for all targets
            for(int i = 0; i<=11; i++){
                //checking the bit is set at given mask
                if(mask & (1<<i)){
                    int req = aliceArrows[i]+1;
                    if(req > rem){
                        score = -1;
                        break;
                    }
                    score += i;
                    bob[i] = req;
                    rem -= req;
                }
            }

            if(score > maxScore){
                if(rem) bob[0] += rem;
                maxScore = score;
                ans = bob;
            }
        }

        return ans;
    }
};

//Approach 4: Using recursion and bitmask
class Solution4 {
public:
    int max_points = 0, max_mask = 0;
    void solve(int k, int numArrows, vector<int>& aliceArrows, int points, int mask) {
        if (numArrows >= 0 && points > max_points) {
            max_points = points;
            max_mask = mask;
        }
        if (k > 0) {
            solve(k - 1, numArrows - aliceArrows[k] - 1, aliceArrows, points + k, mask + (1 << k));
            solve(k - 1, numArrows, aliceArrows, points, mask);
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12);
        solve(11, numArrows, aliceArrows, 0, 0);
        for (int k = 11; k > 0; --k) {
            if (max_mask & (1 << k)) {
                res[k] = aliceArrows[k] + 1;
                numArrows -= aliceArrows[k] + 1;
            }
        }
        res[0] = numArrows;
        return res;
    }
};