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

int getLen(Node* head){

    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

void getMid(Node* head){

    int len = getLen(head);
    int ans = len/2;

    Node* temp = head;
    while(ans--){
        temp = temp->next;
    }
    cout<< temp->data <<endl;
}

Node* getMid1(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){

    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 7);
    insertAtTail(tail, 45);
    insertAtTail(tail, 84);
    insertAtTail(tail, 74);

    
    Node* mid = getMid1(head);
    cout<< mid->data <<endl;
    printL(head);
}