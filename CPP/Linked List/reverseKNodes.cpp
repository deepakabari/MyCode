#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int x){
        val = x;
        next = NULL;
    }
};

//function to insert node at end of the linked list
void insertAtTail(node* &head, int x){
    node* newNode = new node(x);

    if(head == NULL){
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp=temp->next;
    temp->next = newNode;
    return;
}

int lengthOfLinkedList(node* head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head->next;
    }
    return length;
}

// Time Complexity: O(N)

// Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).

// Space Complexity: O(1)

// Reason: No extra data structures are used for computation.

node* reverseKNodes(node* head, int k){
    if(head == NULL || head->next == NULL) return head;
    int length = lengthOfLinkedList(head);

    node* dummy = new node(0);
    dummy->next = head;

    node* pre = dummy;
    node* cur;
    node* nex;

    while(length >= k){
        cur = pre->next;
        nex = cur->next;
        for(int i = 1; i<k; i++){
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummy->next;
}
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){

    node* head=NULL;
    int k = 3;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    
    cout << "Original Linked List is : "; printList(head);
    cout << "After reverse K nodes: ";
    node* newHead = reverseKNodes(head, k);
    printList(newHead);

    return 0;
}