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

/*
//Function to check presence of instersection
//Brute Force Approach
//Keep any one of the list to check its node present in the other list.
//T.C.->O(m*n),  S.C.->O(1)

node* intersection(node* head1, node* head2){
    while(head2 != NULL){
        node* temp = head1;
        while(temp != NULL){
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return NULL
    return NULL;
}

*/

/*
//Another Approch:(using Hashing)
//here we perform searching but using hashing as it takes O(1) time comp.
//T.C.->O(m+n),  S.C.->O(n) as we storing the nodes in set.

node* intersection(node* head1, node* head2){
    unordered_set<node*> st;
    while(head1 != NULL){
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2 != NULL){
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}

*/

//funtion to find differnce of two linked lists
int getDifference(node* head1, node* head2){
    int len1 = 0, len2 = 0;
    while(head1 != NULL || head2 != NULL){
        if(head1 != NULL){
            len1++;
            head1 = head1->next;
        }
        if(head2 != NULL){
            len2++;
            head2 = head2->next;
        }
    }
    return len1-len2;
}

/*
//Better Approach (Using Diff. of length)
//T.C.->O(2max(len. of l1, len. of l2)) + O(abs(len.of l1, len. of l2)) + O(min(len. of l1, len. of l2))
//S.C.->O(1)

node* intersection(node* head1, node* head2){
    int diff = getDifference(head1, head2);
    if(diff < 0)
        while(diff++ != 0) head2 = head2->next;
    else while(diff-- != 0) head1 = head1->next;
    while(head1 != NULL){
        if(head1 == head2) return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;
}

*/

//Optimized Approach
//T.C.->O(2max(length of list1, length of list2))
//S.C.->O(1)

node* intersection(node* head1, node* head2){
    node* d1 = head1;
    node* d2 = head2;

    while(d1 != d2){
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }
    return d1;
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
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    node* head1 = head;

    head = head->next->next->next;
    node* headsec = NULL;
    insertAtTail(headsec, 3);
    node* head2 = headsec;
    headsec->next = head;
    
    cout << "List1: "; printList(head1);
    cout << "List2: "; printList(head2);

    node* ansNode = intersection(head1, head2);
    if(ansNode == NULL){
        cout << "No Intersection\n";
    } else {
        cout << "The intersection point is " << ansNode->val << endl;
    }
    return 0;
}