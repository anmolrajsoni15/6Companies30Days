#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        pair<int, int> dfs(int i, int prev, int dist, int bob, vector<vector<int>> &al, vector<int>& amount) {
            int res = INT_MIN, open = i == bob ? dist + 1 : 0;
            for (auto j : al[i])
                if (j != prev) {
                    auto res_j = dfs(j, i, dist + 1, bob, al, amount);
                    res = max(res, res_j.first);
                    open = max(open, res_j.second);
                }
            if (open)
                amount[i] = open == 1 ? amount[i] / 2 : 0;
            return {(res == INT_MIN ? 0 : res) + amount[i], open - 2 };
        }
    
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            vector<vector<int>> al(amount.size());
            for (auto &e : edges) {
                al[e[0]].push_back(e[1]);
                al[e[1]].push_back(e[0]);
            }
            return dfs(0, -1, 0, bob, al, amount).first;
        }
};
