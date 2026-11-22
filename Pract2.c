// Just a basic understanding of linked list..

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;


void inputList(Node **head, int size);
void displayAndSumOdd(Node *head);
void freeList(Node **head);

int main() {
    Node *head = NULL;
    int size;

    printf("Enter number of nodes: ");
    scanf("%d", &size);


    inputList(&head, size);
    displayAndSumOdd(head);
    freeList(&head);

    return 0;
}


void inputList(Node **head, int size) {
    Node *temp = NULL;
    
    for(int i = 0;i < size;i++){
        //forgot to allocate..
    Node *newNode = malloc(sizeof(Node));
    
    if(!newNode) return;

    //input part
    printf("-> ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        temp = newNode;
    }else{
        temp->next = newNode;
        temp = newNode;
    }
    }
}

void displayAndSumOdd(Node *head) {

    int sum = 0;
    Node *trav = head;

    while(trav != NULL){
        printf("[ %d ", trav->data);
        printf("] -> ");
        trav = trav->next;

    }

    printf("NULL\n");
   
    Node *temp = head;
    while(temp != NULL){
        if(temp->data % 2 != 0 || temp->data % 2 == 0){ //btw ts condition only works in intigers so ya...
            sum += temp->data;
        }
        temp = temp->next;
    }

    printf("\n\nSum [ %d", sum);
    printf(" ]\n");
}


void freeList(Node **head) {
    
    Node *temp = *head;
    while(temp != NULL){
        Node *newNode = temp->next;
        free(temp);
        temp = newNode;
    }
    *head = NULL;
    
}
