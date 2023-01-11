#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        char next = '1';
        int i = 2;
        int ans = 1;
        while(s.size()<n){
            int temp = s[i]-'0';
            while(temp--){
                s.push_back(next);
                if(s.size()<=n && next == '1')
                    ans++;
            }
            i++;
            next = (next == '1')?'2':'1';
        }
        return ans;
    }
};