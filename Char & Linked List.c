/*

    Practice done by: Juan Manuel M. Jurado
    
    This is a basic linked list input output but 
    with 2 kinds datatype and a search function.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char code;
    int quantity;
    struct Node *next;
} Node;


void inputList(Node **head, int size);
void displayList(Node *head);
void searchQuantity(Node *head, char target);
void freeList(Node **head);

int main() {

    Node *head = NULL;
    int size;
    char target;

    printf("Enter number of items: ");
    scanf("%d", &size);

    inputList(&head, size);
    displayList(head);

    printf("\nEnter code to search: ");
    scanf(" %c", &target);
    searchQuantity(head, target);
    freeList(&head);

    return 0;
}

void inputList(Node **head, int size) {
    Node *temp = NULL;
        printf("Code  Quantity\n");
    for(int i = 0; i < size;i++){
        Node *newNode = malloc(sizeof(Node));
        if(!newNode) return;
        
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
    Node *display = head;
    //kinda sure about this part
    //however please check before running
    while(display != NULL){
        printf("[%c] [%d] ", display->code, display->quantity);
        display = display->next;
    }

}


/*The search function in linked list is byfar 
needs a bit research and shi */
void searchQuantity(Node *head, char target) {
    //also the char and quantity search either way.
    int sum = 0;
    Node *temp = head;

    while(temp != NULL){
        
        if(temp->code == target){
            //kinda confused abt ts
            sum += temp->quantity;
        }

        temp = temp->next;
    }

    //The first problem was here and it was the output parameter wrong..
    printf("Data\n [%c][%d]\n", target, sum);
}


void freeList(Node **head) {
    //not entirely sure abt this
    //please check before running..
    //and also embed the char part..
    Node *temp = *head;
    while(temp != NULL){
        Node *newNode = malloc(sizeof(Node));
        free(temp);
        temp = newNode;
    }
    *head = NULL;

}