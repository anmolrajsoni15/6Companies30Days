#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int finalAns = 0;
        for(int i = 0; i<points.size(); i++){
            unordered_map<double, int> mp;
            int repeating = 1;
            for(int j = i+1; j<points.size(); j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    repeating++;
                else if(points[i][0] == points[j][0])
                    mp[INT_MAX]++;
                else{
                    double slope = double(points[i][1]-points[j][1])/double(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }

            int max_cnt = 0;
            for(auto it: mp){
                max_cnt = max(max_cnt, it.second);
            }
            max_cnt += repeating;
            finalAns = max(finalAns, max_cnt);
        }
        return finalAns;
    }
};