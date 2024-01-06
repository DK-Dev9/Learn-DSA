#include <bits/stdc++.h>
#include "LinkedListAll.cpp"
void insertAtTail(Node* &tail, int d);
void printL(Node* &head);

void sort(Node* &first, Node* &second){
    Node* curr1 = first ;
    Node* next1 = first->next;
    Node* curr2 = second;

    while(next1 != NULL && curr2 != NULL){

        if( (curr1->data <= curr2->data) && (curr2->data <= next1->data) ){
            curr1->next = curr2;
            curr1 = curr2;
            curr2 = curr2->next;
            curr1->next = next1;
        }else{
            curr1 = next1;
            next1 = curr1->next;
            if(next1 == NULL){
                curr1->next = curr2;
            }
        }
    }
    return;
}

int main(){
    Node* node1 = new Node(2);
    Node* head1 = node1;
    Node* tail1 = node1;
    // insertAtTail(tail1, 3);
    // insertAtTail(tail1, 6);


    Node* node2 = new Node(1);
    Node* head2 = node2;
    Node* tail2 = node2;
    // insertAtTail(tail2, 3);
    // insertAtTail(tail2, 6);

    Node* first;
    Node* second;

    if(head1->data <= head2->data){
        
        first = head1;
        second = head2;
    }else{
        first = head2;
        second = head1;
    }

    sort(first, second);
    printL(first);
}