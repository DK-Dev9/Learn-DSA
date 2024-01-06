#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL){
            return list2;
        } 
        if(list2 == NULL){
            return list1;
        }

        ListNode* first = NULL;
        ListNode* ans = NULL;
        ListNode* next1 = NULL;
        ListNode* second = NULL;

        if(list1->val<=list2->val){
            first = list1;
            ans = first;
            next1 = first->next;
            second = list2;
        }else{
            first = list2;
            ans = first;
            next1 = first->next;
            second = list1;
        }

        while(next1 != NULL && second != NULL){
            if(first->val<=second->val && second->val<=next1->val){
                first->next = second;
                first = second;
                second = first->next;
                first->next = next1;
            }else
                first = next1;
                next1 = first->next;
                if(next1==NULL)
                    first->next = second;
        }
        if(second!=NULL){
            first->next = second;
        }
        return ans;
    }
};