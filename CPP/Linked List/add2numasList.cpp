#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int x){
        val = x;
        next=NULL;
    }
};
void insertAtTail(node *&head, int x)
{
    node *n = new node(x);
    if (head == NULL) {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//T.C.->O(max(m,n))   S.C.->O(max(m,n)) basically max(m,n)+1
node* addTwoNumbers(node* head1, node* head2){
    node* dummy = new node(0);
    node* temp = dummy;
    int carry = 0;

    while(head1 != NULL || head2 != NULL || carry != 0){
        int sum = 0;
        if(head1 != NULL){
            sum += head1->val;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->val;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        node* Node = new node(sum % 10);
        temp->next = Node;
        temp = temp->next;
    }
    return dummy->next;
}
int main(){

    node* head1 = NULL;
    node* head2 = NULL;
    insertAtTail(head1, 2);
    insertAtTail(head1, 4);
    insertAtTail(head1, 3);
    display(head1);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    insertAtTail(head2, 4);
    display(head2);

    node* newHead = addTwoNumbers(head1, head2);
    display(newHead);
    
    return 0;
}