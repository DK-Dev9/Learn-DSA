#include <bits/stdc++.h>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int elem){

    if(stack.empty()){
        stack.push(elem);
        return;
    }
    int val = stack.top();
    stack.pop();

    insertAtBottom(stack, elem);

    stack.push(val);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }

    int val = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, val);
}