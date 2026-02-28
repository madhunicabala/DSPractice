#include "SLL.h"
/*
This file will include all types of reverse Linked list variants.

1. reverse Entire List
2. reverse List between positions x and y
3. reverse using K groups
4. reverse in pairs (generic to K=2 in above code).
5. reverse alternate positions
*/

void reverseLinkedList(Node** head){
    // in place reversal
    // check if head is null or only one node is present.
    if (!head || !(*head) || !(*head)->next){
        return; // nothing to reverse - 0 / 1 nodes only;;
    }
    Node* curr = *(head);
    Node* prev = NULL;
    Node* next = NULL;
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *(head) = prev;
}


void push(Node* info){
    // if you try to do memcpy to uninitialised node, it will crash.
    if (topval >=99){
        printf("Stack is already full pop smething \n\n");
        return;
    }
    stack[++topval] = info;
}

void pop(){
    if (topval <= -1){
        printf("nothing to pop - stack is empty \n\n");
        return;
    }
   topval--;
}

Node* top(){
    if (topval < 0){
        return NULL;
    }
    return (stack[topval]);
}

void reverseLinkedListUsingStack(Node **head){
    // using an external DS stack and modify the Linked List in place.
    // define stack data structure.
    if (!head || !(*head)->next){
        return;
    }
    // push all nodes to stack and pop them.
    Node* temp = *head;
    while (temp){
        push(temp);
        temp = temp->next;
    }
    Node* newhead = top();
    pop();
    Node* curr = newhead;
    while(topval >=0){
        curr->next = top();
        pop();
        curr = curr->next;
    }
    curr->next = NULL;
    *head = newhead;
}
