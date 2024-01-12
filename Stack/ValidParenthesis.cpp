#include <bits/stdc++.h>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                ans.push(ch);
            }else{
                char ch1 = ans.top();
                if(!ans.empty()){
                if((ch1 == '(' && ch == ')') || (ch1 == '{' && ch == '}') || (ch1 == '[' && ch == ']')){
                    ans.pop();
                }else{
                    return false;
                }}else
                    return false;
            }
        }
        if(ans.empty()){
            return true;
        }
        return false;
    }
};