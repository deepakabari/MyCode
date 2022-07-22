#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int num;
    node* next, *bottom;
    node(int val){
        num = val;
        next = NULL;
        bottom = NULL;
    }
};

//T.C.->O(N), S.C.->O(1)
node* mergeTwoLists(node* a, node* b){
    node* temp = new node(0);
    node* res = temp;

    while(a != NULL && b != NULL){
        if(a->num < b->num){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a) temp->bottom = a;
    else temp->bottom = b;

    return res->bottom;
}

node* flatten(node* root){
    if(root == NULL || root->next == NULL){
        return root;
    }
    // recur. for list on right
    root->next = flatten(root->next);

    // now merge
    root = mergeTwoLists(root, root->next);

    //return root 
    //it will be turn merged with its left
    return root;
}
