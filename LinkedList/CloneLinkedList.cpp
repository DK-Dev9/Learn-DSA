#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* next = new Node(d);
        if(tail == NULL || head==NULL){
            head = next;
            tail = next;
        }else{
            tail->next = next;
            tail = next;
        }
    }

    Node* copyRandomList(Node* head) {
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        
// create A Clone Linked List
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        Node* next = NULL;
        temp = head;
        Node* cloneNode = cloneHead;

// Connect Origin and Clone List
        while(temp != NULL){
            next = temp->next;
            temp->next = cloneNode;
            temp = next;

            next = cloneNode->next;
            cloneNode->next = temp;
            cloneNode = next;
        }

// Insert Random Pointer in Clone Linked List
        temp = head;
        cloneNode = cloneHead;
        while(temp != NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;    
        }

// Cancel Changes
        temp = head;
        cloneNode = cloneHead;
        while(temp != NULL){
            temp->next = cloneNode->next;
            temp = temp->next;
            if(temp!=NULL){
                cloneNode->next = temp->next;
            }
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};

