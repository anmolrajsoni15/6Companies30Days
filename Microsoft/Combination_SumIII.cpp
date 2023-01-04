#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int> &box, vector<int> &cont, int tar, int k){
        if(i>=box.size()){
            if(cont.size() == k && tar == 0)
                ans.push_back(cont);
            return;
        }

        //take
        if(box[i]<=tar){
            cont.push_back(box[i]);
            solve(i+1, box, cont, tar-box[i], k);
            cont.pop_back();
        }

        //not take
        solve(i+1, box, cont, tar, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> box;
        for(int i = 1; i<=9; i++)
            box.push_back(i);
        vector<int> cont;

        solve(0, box, cont, n, k);

        return ans;
    }
};