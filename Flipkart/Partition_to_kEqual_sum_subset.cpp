#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool solve(vector<int>& nums, int i, int n, int k, int curr, int tar, vector<bool>& vis){
        if(k == 1)  return true;
        if(i >= n) //This line is important to avoid tle
           return false;

        if(curr == tar)
            return solve(nums, 0, n, k-1, 0, tar, vis);

        for(int x = i; x<n; x++){
            if(vis[x] || curr+nums[x] > tar)    continue;

            vis[x] = true;
            if(solve(nums, x+1, n, k, curr+nums[x], tar, vis))
                return true;

            vis[x] = false;
            if(curr == 0)   break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums)   sum+=i;

        if(sum%k || n<k)
            return false;
        
        sum /= k;
        vector<bool> visited(n, false);

        return solve(nums, 0, n, k, 0, sum, visited);
    }
};

//using bitmask
class Solution2 {
public:

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums)   sum+=i;

        if(sum%k || n<k)
            return false;
        
        sum /= k;
        vector<int> dp((1<<16)+2, -1);
        dp[0] = 0;

        for(int mask = 0; mask < (1<<n); mask++){
            if(dp[mask] == -1)  continue;

            for(int i = 0; i<n; i++){
                if(!(mask&(1<<i)) && dp[mask]+nums[i] <= sum)
                    dp[mask|(1<<i)] = (dp[mask]+nums[i])%sum;
            }
        }

        return dp[(1<<n)-1] == 0;
    }
};