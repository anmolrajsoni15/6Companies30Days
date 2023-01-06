#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, int> mp1, mp2;
        int n = secret.size();
        int bull = 0, cow = 0;

        for(int i = 0; i<n; i++){
            if(secret[i] == guess[i]){
                bull++;
            }
            else{
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
        }

        for(auto it: mp1){
            if(mp2.count(it.first))
                cow += min(mp2[it.first], it.second);
        }

        string ans = "";
        ans = to_string(bull)+"A"+to_string(cow)+"B";

        return ans;
    }
};