#include<iostream>
using namespace std;

class node{
public:
    int num;
    node* next;

    node(int val){
        num = val;
        next = NULL;
    }
};

void insertNode(node* &head, int x){
    node* n = new node(x);
    if(head==NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = n;
    return;
}
/*
//Brute fotce approach
//T.C.->O(Number of nodes present in the list*k)
//S.C.->O(1)
node* rotateRight(node* head, int k){
    if(head == NULL || head->next == NULL) return head;

    for(int i = 0; i<k; i++){
        node* temp = head;
        while(temp->next->next != NULL){
            temp= temp->next;
        }
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
*/
//optimal Approach
//T.C.->O(length of list) + O(length of list – (length of list%k))     S.C.->O(1)
node* rotateRight(node* head, int k){
    if(!head || !head->next || k == 0) return head;
    node* temp = head;
    int length = 1;
    while(temp->next){
        length++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % length;
    int end = length - k;
    while(end--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;

}

void display(node* head){
    while(head != NULL){
        cout << head->num << "->";
        head=head->next;
    }
    cout << "NULL" << endl;
    return;
}
int main(){

    node* head = NULL;
    insertNode(head, 1);    
    insertNode(head, 2);    
    insertNode(head, 3);    
    insertNode(head, 4);    
    insertNode(head, 5);    
 
    cout << "Original Lists: ";
    display(head);

    int k = 2;
    node* newHead = rotateRight(head, k);

    cout << "After " << k << " iteration: ";
    display(newHead);

    return 0;
}