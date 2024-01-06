#include <bits/stdc++.h>
#include "LinkedListAll.cpp"
void insertAtTail(Node* &tail, int d);
void printL(Node* &head);

using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int d){
//         data = d;
//         next = NULL;
//     }
// };

// void insertAtTail(Node* &tail, int d){
//     Node* temp = new Node(d);
//     tail->next = temp;
//     tail = temp;
// }

// void printL(Node* &head){
//     Node* temp = head;
//     while(temp!=NULL){

//         cout<< temp->data <<" ";
//         temp = temp->next;
//     }
//     cout<<endl; 
// }

void rmvDuplicate(Node* &head){

    Node* curr = head;
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* next = curr->next->next;
            Node* nodeToDel = curr->next;
            delete(nodeToDel);
            curr->next = next;
        }else{
            curr = curr->next;
        }
    }
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);

    rmvDuplicate(head);

    printL(head);


}