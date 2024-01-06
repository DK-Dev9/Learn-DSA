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

void insertAtTail(Node* &tail, Node* &head, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
    tail->next = head;

}

void printL(Node* &head){
    Node* temp = head;
    while(temp!=NULL){

        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl; 
}

bool isCircular(Node* head){

    if(head == NULL)
        return true;

    Node* temp = head->next;
    while(temp != NULL & temp != head){
        temp = temp->next;
    }

    if(temp == head)
        return true;
    return false;
}

map<Node*, bool> vis;
int flag = 0;

bool isCircularMap(Node* head){
    
    // Base Case
    if(head == NULL) 
        return false;
    // Is Visited
    if(!vis[head]){ // Not Visited
        vis[head] = true; // mark Visited
        isCircularMap(head->next);
    }else{  // Visited
        return true;
    }
}
int main(){

    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail,head, 7);
    insertAtTail(tail,head, 45);
    insertAtTail(tail,head, 84);
    insertAtTail(tail,head, 74);

    if(isCircularMap(head))
        cout<< "Linked list is completely circular" <<endl;
    else 
        cout<< "Not Circular" <<endl;
}