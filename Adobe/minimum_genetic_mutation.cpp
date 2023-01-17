#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> mp;
        for(auto it: bank)
            mp[it]++;

        if(!mp.count(end))  return -1;
        
        int ans = 0;
        queue<string> q;
        q.push(start);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string top = q.front();
                q.pop();

                if(top == end)
                    return ans;

                mp.erase(top);
                for(int i = 0; i<8; i++){
                    string temp = top;
                    temp[i] = 'A';
                    if(mp.count(temp))
                        q.push(temp);

                    temp[i] = 'C';
                    if(mp.count(temp))
                        q.push(temp);

                    temp[i] = 'G';
                    if(mp.count(temp))
                        q.push(temp);

                    temp[i] = 'T';
                    if(mp.count(temp))
                        q.push(temp);  
                }
            }
            ans++;
        }

        return -1;
    }
};