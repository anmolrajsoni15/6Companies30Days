#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto num : nums)
            freq[num]++;

        unordered_map<int, int> req;

        for(int n : nums){
            if(freq[n] == 0)    continue;

            if(req[n]>0){
                freq[n]--;
                req[n]--;
                req[n+1]++;
            }
            else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                req[n+3]++;
            }
            else return false;
        }

        return true;
    }
};