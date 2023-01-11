#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        int prev = 0;
        for(int i = 0; i<cards.size(); i++){
            mp[cards[i]].push_back(i+1);
        }

        for(auto it: mp){
            if(it.second.size()>1){
                for(int i = 0; i<it.second.size()-1; i++){
                    ans = min(ans, it.second[i+1]-it.second[i]+1);
                }
            }
        }

        if(ans == INT_MAX)
            return -1;
        else    return ans;
    }
};