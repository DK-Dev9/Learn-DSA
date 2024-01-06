#include <bits/stdc++.h>
#include "LinkedListAll.cpp"
void insertAtTail(Node* &tail, int d);
void printL(Node* &head);

Node* reverseA(Node* &head){

    if(head->next==NULL || head==NULL){
        return head;
    }
    Node* chotaHead = reverseA(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}
void insert(Node* &head, Node* &tail, int d){
    if(tail == NULL || head == NULL){
        Node* node1 = new Node(d);
        head = node1;
        tail = node1;
    }else
        insertAtTail(tail, d);
}

Node* addSum(Node* head1, Node* head2){

    int carry = 0;
    int digit = 0;
    int value = 0;
    Node* head = NULL;
    Node* tail = NULL;

        while(head1!=NULL && head2!=NULL){
            value = (head1->data + head2->data) + carry;
            digit = value%10;
            carry = value/10;
            insert(head, tail, digit);
            head1 = head1->next;
            head2 = head2->next;
        }
       
        while(head1!=NULL){
            value = head1->data + carry;
            digit = value%10;
            carry = value/10;
            insert(head, tail, digit);
            head1 = head1->next;
        }
        while(head2!=NULL){
            value = head2->data + carry;
            digit = value%10;
            carry = value/10;
            insert(head, tail, digit);
            head2 = head2->next;
        }
         
        while(carry != 0){
            value = carry;
            digit = value%10;
            carry = carry/10;
            insert(head, tail, digit);
        }
   
    head = reverseA(head);
    return head;
}

int main(){
    Node* node1 = new Node(1);
    Node* head1 = node1;
    Node* tail1 = node1;
    insertAtTail(tail1,2);
    insertAtTail(tail1,3);
    //  Reverse Both Linked List for SUM
    head1 = reverseA(head1);

    Node* node2 = new Node(1);
    Node* head2 = node2;
    Node* tail2 = node2;
    insertAtTail(tail2,3);
    insertAtTail(tail2,2);
    insertAtTail(tail2,1);
    head2 = reverseA(head2);

    Node* head = addSum(head1, head2);
    printL(head);



}