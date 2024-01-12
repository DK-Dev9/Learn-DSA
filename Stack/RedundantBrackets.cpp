// (( a+b )) => redundant Brackets
// (a + (b*c)) => Not-Redundant Brackets
#include <bits/stdc++.h> 
using namespace std;

bool opr(char c){

    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    return false;
}

// Time complexity => O(n)
// Space Complexity => O(n)

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> ans;

    for(int i=0; i<s.length(); i++){

        if(s[i]=='(' || opr(s[i]) ){

            ans.push(s[i]);
        }else{
            bool isRedundent = true;
            if(s[i]==')'){
                while(ans.top() != '('){
                    if (opr(ans.top())) {
                        ans.pop();
                        isRedundent = false;
                    }
                }
                ans.pop();
                if(isRedundent){
                    return true;
                }
            }
        }
    }
    return false;
}
