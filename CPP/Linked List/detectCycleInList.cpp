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

void createCycle(node* &head, int pos){
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(node* head){
    if(head == NULL) return false;
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}

//function to print linked list created
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    printList(head);
    createCycle(head, 2);
    printList(head);
    if(detectCycle(head) == true){
        cout << "Cycle Detected" << endl;
    } else {
        cout << "Cylce Not Detected" << endl;
    }
    return 0;
}