#include <stdio.h>
#include <stdlib.h>

// Structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function Prototypes
void inputList(Node **head, int size);
void displayAndSumOdd(Node *head);
void freeList(Node **head);

int main() {
    Node *head = NULL;
    int size;

    printf("Enter number of nodes: ");
    scanf("%d", &size);

    // Input linked list
    inputList(&head, size);

    // Display linked list and calculate odd sum
    displayAndSumOdd(head);

    // Free allocated memory
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
    // YOUR CODE HERE
    Node *temp = head;
    while(temp != NULL){
        if(temp->data % 2 != 0 || temp->data % 2 == 0){
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