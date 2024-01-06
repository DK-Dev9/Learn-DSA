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

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void printL(Node* &head){
    Node* temp = head;
    while(temp!=NULL){

        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl; 
}

Node* reverseKG(Node* head, int k){
    if(head == NULL)
        return NULL;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    int cnt=0;
    while(curr != NULL && cnt<k){

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
        // head = prev;
    }
    if(forward != NULL){
        head->next = reverseKG(forward, k);
    }    
    return prev;
    
}

int main(){

    
    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 7);
    insertAtTail(tail, 45);
    insertAtTail(tail, 84);
    insertAtTail(tail, 74);

    head = reverseKG(head, 2);
    printL(head);

}