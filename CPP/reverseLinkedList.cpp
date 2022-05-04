#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//Brute Force Approach
//T.C. -> O(N), S.C.-> O(1)
/*
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev_p = NULL;
        ListNode* current_p = head;
        ListNode* next_p;

        while(current_p){
            next_p = current_p->next;
            current_p->next = prev_p;

            prev_p = current_p;
            current_p = next_p;
        }
        head = prev_p;
        return head;
    }
};
*/
//Better Approach(Recursive)
//T.C. -> O(N), S.C.-> O(1)
/*
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* newHead = NULL;
        while(head != NULL){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};
*/
//Better Approach(Recursive)
//T.C. -> O(N), S.C.-> O(1)
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newNode;
    }
};
