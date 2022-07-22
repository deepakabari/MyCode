#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//Better Approach
//T.C. -> O(N), S.C.-> O(1)
/*
class Solution{
public:
    ListNode* middleNode(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }    
};
*/
//Brute Force Approach
//T.C. -> O(N + N/2), S.C.-> O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head){
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;
        for(int i = 0; i < n/2; i++){
            temp = temp->next;
        }
        return temp;
    }
};

