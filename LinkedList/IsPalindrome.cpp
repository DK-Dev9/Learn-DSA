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

bool check(vector<int> arr){

    int n = arr.size();
    for(int i=0; i<=n/2; i++){
        if(arr[i] != arr[n-i-1])
            return false;
    }
    return true;
}

bool isPalindrome(Node* head){

    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return check(arr);
}

int getLen(Node* head){

    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

bool checkPalindrom(Node* head){
    Node*  temp = head;
    int len = getLen(temp);
    int mid = len/2;
    while(mid--){
        temp = temp->next;
    }
   
    temp->next = reverseA(temp->next);
    temp = temp->next;
    while(temp!=NULL){
        if(head->data != temp->data){
            return false;
        }
        head = head->next;
        temp = temp->next;
    }
    return true;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,2);
    insertAtTail(tail,1);


    // if(isPalindrome(head))
    //     cout<< "its Palindrome guys chilll..." <<endl;
    // else
    //     cout<< "its NOT Palindrome guys chill...." <<endl;

    if(checkPalindrom(head)){
        cout<< "its palindrome...";
    }else
        cout<< "its not palindrome";
}