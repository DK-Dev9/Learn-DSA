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

void reverseRecursion(Node* &head, Node* curr, Node* prev){

    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    curr->next = prev;
    reverseRecursion(head, forward, curr);
}

void reverseIterative(Node* &head){

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    while(curr != NULL){

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        head = prev;
    }
}

Node* reverseA(Node* &head){

    if(head->next==NULL || head==NULL){
        return head;
    }
    Node* chotaHead = reverseA(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

void printL(Node* &head){
    Node* temp = head;

    while(temp!=NULL){

        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 7);
    insertAtTail(tail, 45);
    insertAtTail(tail, 84);
    insertAtTail(tail, 74);

    Node* curr = head;
    Node* prev = NULL; 

    // reverseRecursion(head, curr, prev);
    reverseIterative(head);
    head = reverseA(head);

    printL(head);

}