#include <bits/stdc++.h>
#include "LinkedListAll.cpp"
using namespace std;
void insertAtTail(Node* &tail, int d);
void printL(Node* &head);

void sort(Node* head){
    if(head == NULL)
        return;
    Node* temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    while (temp != NULL)
    {
        if(temp->data == 0)
            cnt0++;
        else if(temp->data == 1)
            cnt1++;
        else if(temp->data == 2)
            cnt2++;
        temp = temp->next;  
    }
    temp = head;
    while(temp != NULL){
        if(cnt0 != 0){
            temp->data = 0;
            cnt0--;
        }else if(cnt1 != 0){
            temp->data = 1;
            cnt1--;
        }else if(cnt2 != 0){
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
}

int main(){
    Node* node1 = new Node(2);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);

    sort(head);
    printL(head);


}