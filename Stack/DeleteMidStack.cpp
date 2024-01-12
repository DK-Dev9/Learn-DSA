#include <bits/stdc++.h>
#include <stack>
using namespace std;

void solve(stack<int> &inp, int count, int n){  
    if(count==n/2){
        inp.pop();
        return;    
    }

    int temp = inp.top();
    inp.pop();

    solve(inp, count+1, n);
    inp.push(temp);  
}

int main(){

    stack<int> st;
    st.push(48);
    st.push(36);
    st.push(24);
    st.push(12);
    int count = 0;
    int n = st.size();
    solve(st, count, n);
    for(int i=0; i<n; i++){
        cout<< st.top()<< " ";
        st.pop();
    }
   
}