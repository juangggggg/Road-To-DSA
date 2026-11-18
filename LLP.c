/*
Basic Input-output in Linked List in c
js to practice for finals ahh program

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void input(Node **head, int size);
void print(Node *head, int size);

int  main(){
    Node *head = NULL;

    int size;

    printf("Enter Number of Nodes\n->");
    scanf("%d", &size);


    input(&head, size);
    print(head, size);

    return 0;
}


void input(Node **head, int size){
    Node *temp = NULL;

    for(int i = 0;i < size;i++){
        Node *newNode = malloc(sizeof(Node));

        if(!newNode) return;
        printf("Enter Node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(!*head) *head = newNode;
        else temp->next = newNode;

        temp = newNode;
    }
}
void print(Node *head, int size){
    for(int i = 0;i < size;i++){
        printf("%d ->", head->data);
        head = head->next;

    }
    printf(" NULL\n");
}
