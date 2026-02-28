#ifndef SLL_H
#define SLL_H
#include <stdio.h>
#include <stdlib.h>

// Best to use void* - real time aligned.
typedef struct Node{
    void* data;
    struct Node* next;
}Node;
Node* createnewNode(int data);
void insertAtStart(Node** head, int value);
void insertAtEnd(Node** head, int value);
void deleteAtStart(Node** head);
void deleteAtEnd(Node** head);
void traverse(Node* head);
void freeNodes(Node** head);

#endif