/*
This conatins a basic structure of SLL .
*/

#include<stdio.h>
#include<stdlib.h>

// Best to use void* - real time aligned.
typedef struct Node{
    void* data;
    struct Node* next;
}Node;

// I will not maintain global head pointer.

Node* createnewNode(int data){
    Node* newnode = malloc(sizeof(struct Node));
    if (NULL == newnode)
        return NULL;
    newnode->next = NULL;
    newnode->data = malloc(sizeof(int));
    *(int*)newnode->data = data;
    return newnode;
}
void insertAtstart(Node** head, int value){
    Node* newnode = createnewnode(value);
    newnode->next = (*head);
    (*head) = newnode;
    return;
}

void freeNodes(Node* head){
    Node* temp = head;
    while (temp != NULL){
        Node* next = temp->next;
        free(temp->data);
        temp->data = NULL;
        free(temp);
        temp = next;
    }
}

void insertAtEnd(Node** head , int data){
    // head is NULL
    if (!(*head)){
        insertAtstart(head, data);        
    }
    //head is NOT NULL
    else {
        Node* newnode = createnewnode(data);
        Node* temp = *head;
        while (temp->next !=NULL){
            // traverse till last node.
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void deleteAtStart(Node** head){
    //head is NULL - nothing to delete/
    if (!head || !(*head))
        return;
    // head is NOT NULL.
    Node* temp = *(head);
    *(head) = temp->next;
    free(temp->data);
    temp->data = NULL;
    free(temp);
}

void deleteAtEnd(Node** head){
    if (!head || !(*head))
    return;
    // head is NOT NULL.- only Node - needs special handling.
    if ((*head)->next == NULL) {
        // single node
        free((*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *(head);
    Node* prev = temp;
    while (temp->next){
        prev = temp;
        temp = temp->next;
    }
    // you have to delete temp;
    prev->next = NULL; // since it is delete at end.
    free(temp->data);
    temp->data = NULL;
    free(temp);
}
void traverse(Node* head){
    if (NULL == head){
        return;
    }
    Node* temp = head;
    while (temp){
        temp->data ? (printf("%d--> " , *(int*)temp->data)) : (printf("Data is Empty --> "));
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    insertAtstart(&head, 100);
    insertAtstart(&head, 101);
    insertAtEnd(&head, 900);
    insertAtEnd(&head, 901);
    deleteAtStart(&head);
    deleteAtEnd(&head);
    traverse(head);
    freeNodes(head);
}
