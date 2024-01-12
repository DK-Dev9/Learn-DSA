#include <bits/stdc++.h>
using namespace std;

class Stack{
    
    
    public:
    int size;
    int top;
    int *arr;
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }


    void push(int val){
        if(top<size-1){
            top++;
            arr[top] = val;
        }else{
            cout<< "Stack Overflow " <<endl;
        }
    }
    void pop(){
        if(top<0){
            cout<< "Stack Underflow " <<endl;
        }else{
            top--;
        }
    }
    int peek(){
        cout<< endl;
        if(top>=0 && top<size){
            return arr[top];
        }else{
            cout<< "Stack is Empty " <<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }

};
int main(){

    Stack st(5);
    st.push(23);
    st.push(33);
    st.push(43);
    st.push(53);
    st.push(63);
    // st.push(73);
    // st.push(93);
    // st.push(13);

    cout<< st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<< st.peek();


}