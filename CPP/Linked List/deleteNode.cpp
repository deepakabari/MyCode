#include<iostream>
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
//function to insert node at the end of the list
void insertAtTail(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
//function to get reference of the node to delete
node* getNode(node* head,int val) {
    while(head->val != val) head = head->next;
    
    return head;
}
//delete function as per the question
void deleteNode(node* t) {
    t->val = t->next->val;
    t->next = t->next->next;
    return;
}
//printing the list function
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<head->val<<"\n";
}
int main() {
    node* head = NULL;
    //inserting node
    insertAtTail(head,1);
    insertAtTail(head,4);
    insertAtTail(head,2);
    insertAtTail(head,3);
    //printing given list
    cout<<"Given Linked List:\n";
    printList(head);
    node* t = getNode(head,2);
    //delete node
    deleteNode(t);
    //list after deletion operation
    cout<<"Linked List after deletion:\n";
    printList(head);
    return 0;
}