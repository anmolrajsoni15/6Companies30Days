#include<bits/stdc++.h>
using namespace std;

class Solution {
    map<vector<int>, int> dp;
    public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (dp.count(needs)) return dp[needs];

        int n = price.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += price[i] * needs[i];

        for (int i = 0; i < special.size(); ++i) {
            vector<int> tmp;
            for (int j = 0; j < n; ++j) {
                if (special[i][j] > needs[j])
                    break;
                tmp.push_back(needs[j] - special[i][j]);
            }
            if (tmp.size() == n) {
                ans = min(ans, shoppingOffers(price, special, tmp) + special[i].back());
            }
        }
        dp[needs] = ans;
        return ans;
    }
};