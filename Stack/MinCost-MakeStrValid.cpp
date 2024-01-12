#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str) {
  // Write your code here
    if(str.length()%2==1){
      return -1;
    }

    stack<char> ans;
    for(int i=0; i<str.length(); i++){

        char ch = str[i];

        if(ch=='{'){

            ans.push(ch);
        }else{
            if(!ans.empty() && ans.top()=='{'){
                ans.pop();
            }else{
                ans.push(ch);
            }
        }
    }

    int a=0, b=0;
    while(!ans.empty()){

        if(ans.top()=='{'){
            a = a+1;
        }else{

            b = b+1;
        }
        ans.pop();
    }

    return ((a+1)/2) + ((b+1)/2);

    
}