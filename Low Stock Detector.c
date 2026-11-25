#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char code;
    int quantity;
    struct Node *next;
} Node;

void inputList(Node **head, int size);
void displayList(Node *head);
void countLowStock(Node *head);
void freeList(Node **head);

int main() {

    Node *head = NULL;
    int size;

    printf("Enter number of items: ");
    scanf("%d", &size);

    inputList(&head, size);
    displayList(head);
    countLowStock(head);
    freeList(&head);

    return 0;
}


void inputList(Node **head, int size) {

    

    Node *temp = NULL;

    printf("C | Q\n");
    for(int i = 0;i < size;i++){
        Node *newNode = malloc(sizeof(Node));

        scanf(" %c %d", &newNode->code, &newNode->quantity);
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

void displayList(Node *head) {
    // YOUR CODE HERE
    Node *temp = head;
    printf("\n\n=====INVENTORY=====\n\n");
    while(temp != NULL){
        printf(" [%c][%d]\n", temp->code, temp->quantity);
        temp = temp->next;

    }
    printf("NULL\n");

}



/*    The loop checks head instead of temp, but head is never 
    updated, causing an infinite loop.It also compares quantity
    with the running count instead of checking against a defined 
    low-stock threshold.*/
void countLowStock(Node *head) {

    int count = 0;
    Node *temp = head;

    printf("\n\n===== LOW STOCK REPORT =====\n\n");
    while(temp != NULL){
        if(temp->quantity < 10){
            
                    printf(" [%c][%d]\n", temp->code, temp->quantity);
            count++;
        }
        temp = temp->next;
        
        
    }
    
    printf("\n\nLow Stock Count: %d", count);
}

void freeList(Node **head) {
    Node *temp = *head;
    while(temp != NULL){
        Node *newNode = malloc(sizeof(Node));
        free(temp);
        temp = newNode;
    }
    *head = NULL;
}