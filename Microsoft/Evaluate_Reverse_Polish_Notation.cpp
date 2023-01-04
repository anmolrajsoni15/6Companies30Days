#include<bits/stdc++.h>

class Solution {
public:

    int returnNum(string s){
        bool isNeg = false;
        int i = 0, n = s.size();
        if(s[0] == '-')
            isNeg = true, i++;

        int num = 0;
        while(i<n){
            int digit = s[i]-'0';
            num = num*10+digit;
            i++;
        }

        if(isNeg)   num = -num;

        return num;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i<tokens.size(); i++){
            char ch = tokens[i][0];
            if((ch == '+' || ch == '-' || ch == '/' || ch == '*') && tokens[i].size() == 1){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    int temp = first + second;
                    st.push(temp);
                }
                else if(tokens[i] == "-"){
                    int temp = first - second;
                    st.push(temp);
                }
                else if(tokens[i] == "*"){
                    int temp = first * second;
                    st.push(temp);
                }
                else if(tokens[i] == "/"){
                    int temp = first / second;
                    st.push(temp);
                }
            }
            else{
                int x = returnNum(tokens[i]);
                st.push(x);
            }
        }

        return st.top();
    }
};