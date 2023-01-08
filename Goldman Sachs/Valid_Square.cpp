#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int distanceSquared(vector<int>& x1, vector<int>& x2){
        int ans = (x1[0]-x2[0])*(x1[0]-x2[0]) + (x1[1]-x2[1])*(x1[1]-x2[1]);
        return ans;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st;
        st.insert(distanceSquared(p1, p2));
        st.insert(distanceSquared(p1, p3));
        st.insert(distanceSquared(p1, p4));
        st.insert(distanceSquared(p3, p2));
        st.insert(distanceSquared(p4, p2));
        st.insert(distanceSquared(p3, p4));

        return (!st.count(0) && st.size() == 2);
    }
};