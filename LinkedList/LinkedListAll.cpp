#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

void printL(Node* head){
    do{
        cout<< head->data;
    }while(head->next!=NULL);
}

void main(){
    Node* node1 = new Node(2);
}