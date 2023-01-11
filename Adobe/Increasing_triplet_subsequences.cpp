#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;

        int a = INT_MAX;
        int b = INT_MAX;

        for(int i = 0; i<nums.size(); i++){
            int c = nums[i];
            if(c > b)
                return true;
            else if(c > a && c < b)
                b = c;
            else if(c < a)
                a = c;
        }

        return false;
    }
};