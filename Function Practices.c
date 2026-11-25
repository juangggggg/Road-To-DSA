/*
LeetCode-style linked list practice focusing on traversal,
pointer manipulation, searching, and problem-solving.
*/

int countOccurrences(Node *head, int target){

    // YOUR CODE HERE
    int count = 0;

    Node *temp = head;
    while(temp != NULL){
        if(temp->data == target){
            
            count++;
        }
        temp = temp->next; 
    }
    return count;
}

Node* findMaximum(Node *head) {
    // YOUR CODE HERE
    if(!head) return NULL;
    int max = head->data;
    Node *maxNode = head;
    Node *trav = head;

    while(trav != NULL){
        if(trav->data > max){
            max = trav->data;
            maxNode = trav;
        }
        trav = trav->next;
    }
    return maxNode;

}