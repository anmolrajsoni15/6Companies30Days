#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //using hashmap and two pointer simple direct approach
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        int n = s.size();

        for(auto it : words)
            mp[it]++;

        for(auto it: mp){
            int x1 = 0, x2 = 0;
            string temp = it.first;
            int k = temp.size();
            while(x1 < n && x2 < k){
                if(s[x1] == temp[x2])
                    x1++, x2++;
                else    x1++;
            }
            if(x2 == k)
                ans += it.second;
        }

        return ans;
    }
};