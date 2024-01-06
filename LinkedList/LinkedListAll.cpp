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

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAt(Node* &head, int n, int d){

    Node* temp = new Node(d);
    // Node* tmp = head;
    int cnt = 1;
    while(cnt < n-2){
        head = head->next;
        cnt++;
    }
    Node* tmp = head->next;
    head->next = temp;
    temp->next = tmp;
}

void printL(Node* &head){
    Node* temp = head;
    if(temp == NULL){
        cout<< "You are empty" <<endl;
    }
    while(temp!=NULL){

        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl; 
}

// int main(){
//     Node* node1 = new Node(2);
//     Node* head = node1;
//     Node *tail = node1;

//     insertAtHead(head, 34);
//     insertAtTail(tail, 9);
//     insertAt(head, 3, 5);
//     printL(head);
// }