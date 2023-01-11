#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)  return "0";
        string ans = "";

        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            ans += '-';

        long long num = llabs(numerator), deno = llabs(denominator);
        long long qot = num/deno;
        long long rem = num%deno;

        ans += to_string(qot);

        if(rem == 0)
            return ans;

        ans += '.';
        unordered_map<long long, long long> mp;
        while(rem != 0){
            if(mp.count(rem)){
                int pos = mp[rem];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else{
                mp[rem] = ans.length();
                rem *= 10;
                qot = rem/deno;
                rem %= deno;
                ans += to_string(qot);
            }
        }

        return ans;
    }
};