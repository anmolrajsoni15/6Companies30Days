#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long, int> mp;
        const long long N = 1000000;
        for(auto rect : rectangles){
            mp[rect[0]*N + rect[1]]++;
            mp[rect[2]*N + rect[3]]++;
            mp[rect[0]*N + rect[3]]--;
            mp[rect[2]*N + rect[1]]--;
        }

        int ans = 0;
        for(auto it: mp){
            if(it.second != 0){
                if(abs(it.second) != 1)
                    return false;
                ans++;
            }
        }

        return ans == 4;
    }
};