#include <bits/stdc++.h> 
    //Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

//Brute Force Approach(By lists)
//T.C.->O(N), S.C.->O(N)
/*
#include <vector>

Node *removeKthNode(Node *head, int K)
{
    if (head == NULL || K == 0)
    {
        return head;
    }

    // It stores all the node of Linked List.
    vector<Node*> nodeList;

    // Creating temporory node.
    Node *temp = head;

    // Iterating the Linked List.
    while (temp != NULL)
    {
        // Add current node to list.
        nodeList.push_back(temp);
        temp = temp->next;
    }

    // If head of Linked List is the Kth node.
    if (K == nodeList.size())
    {
        Node *next = head->next;
        head->next = NULL;
        head = next;
    }
    else
    {
        // Remove the Kth node from end.
        nodeList[nodeList.size() - K - 1]->next = nodeList[nodeList.size() - K]->next;
    }

    return head;
}
*/
//Brute Force Approach(By finding length of list)
//T.C.->O(N), S.C.->O(1)
/*
Node *removeKthNode(Node *head, int K)
{
    if (head == NULL || K == 0)
    {
        return head;
    }

    // It stores the Length of Linked List.
    int L = 0;

    // Creating temporory node.
    Node *temp = head;

    while (temp != NULL)
    {
        L++;
        temp = temp->next;
    }

    // If head of Linked List is the Kth node from end.
    if (K == L)
    {
        Node *next = head->next;
        head->next = NULL;
        head = next;
    }
    else
    {
        int countNode = 0;
        temp = head;

        while (temp != NULL)
        {
            countNode++;

            // Remove the Kth node from end of Linked List.
            if (L - K == countNode)
            {
                temp->next = temp->next->next;
                break;
            }

            temp = temp->next;
        }
    }

    return head;
}
*/
//Another Approach with T.C.->O(N), S.C.->O(1)
//use of slow and fast pointer(rabbit-tortoise approach)
/*



Node* removeKthNode(Node *head, int K)
{
    if(head == NULL || K == 0) return head;
	Node* slow = head;
	Node* fast = head;
	
	for(int i = 0; i < K; i++){

        //if head is the Kth node from end of the list
		if(fast->next == NULL){
			Node* temp = head->next;
			head->next = NULL;
			head = temp;
			return head;
		} else {
			fast = fast->next;
		}
	}
    //Moving both pointers at same speed
	while(fast->next != NULL){
		slow = slow->next;
		fast = fast->next;
		
	}
    //remove Kth node from end of the linked list
	slow->next = slow->next->next;
	return head;
}
*/