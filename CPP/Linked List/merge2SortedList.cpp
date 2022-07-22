#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
node* mergeSortedList(node* head1, node* head2){
    if(head1->data > head2->data)  swap(head1, head2);
        node* res = head1;
        while(head1 != NULL && head2 != NULL){
            node* temp = NULL;

            while(head1 != NULL && head1->data <= head2->data){
                temp = head1;
                head1 = head1->next;
            }
            temp->next = head2;
            swap(head1, head2);
        }
    return res;
}
