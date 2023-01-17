#include<bits/stdc++.h>
using namespace std;

//using queue
class Solution1 {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i<=n; i++)
            q.push(i);

        while(q.size()>1){
            int x = k;
            while(x>1){
                int top = q.front();
                q.pop();
                q.push(top);
                x--;
            }
            q.pop();
        }

        return q.front();
    }
};

// using simple maths
class Solution2 {
public:
    int solve(int n, int k){
        if(n == 1)
            return 0;

        int x = solve(n-1, k);
        return (x+k)%n;
    }

    int findTheWinner(int n, int k) {
        return solve(n, k)+1;
    }
};