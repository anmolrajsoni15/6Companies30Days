#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)
            return nums;

        vector<int> dp(n, 1);
        int maxi = INT_MIN;
        int num = -1;

        sort(nums.begin(), nums.end());
        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(nums[i]%nums[j] == 0){
                    int temp = 1+dp[j];
                    dp[i] = max(temp, dp[i]);
                }
            }
            maxi = max(maxi,dp[i]);
        }

        vector<int> ans;
        for(int i = n-1; i>=0; i--){
            if((dp[i] == maxi) && (num == -1 || num%nums[i] == 0)){
                ans.push_back(nums[i]);
                maxi--;
                num = nums[i];
            }
        }

        return ans;
    }
};