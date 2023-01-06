#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total = 0, front = 0, ans = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            total += nums[i];
            front += (i*nums[i]);
        }
        
        ans = front;
        
        for(int i = nums.size()-1; i>=0; i--) {
            front += total-(nums.size()*nums[i]);
            ans = max(ans, front);
        }
        
        return ans;
    }
};