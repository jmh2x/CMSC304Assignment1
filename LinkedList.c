#include "LinkedList.h"



struct Node* createNode(char* data) //createNode function defined
{   
    //allocating node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL){
            return NULL;
        }
    //allocating data
    newNode->data = (char*)malloc(strlen(data) + 1);
    if(newNode->data == NULL){
        return NULL;
    }
    //copying into data
    strcpy(newNode->data,data);
    //initialize next to NULL
    newNode->next = NULL;
    return newNode;
    
}


void insertAtEnd(struct Node** head, struct Node* newNode){ //InsertAtEnd function defined
    if(*head ==NULL){ //empty list, newNode as head
        *head = newNode;
        return;
    }
    
    if(head == NULL){ //if head is NULl return
        return;
    }
    if(newNode ==NULL){ // if newNode is NULL return
        return;
    }
    struct Node* start =*head; //start from head
    while(start->next != NULL){ // traverse to end
        start = start->next;
    }
    start->next=newNode; // append newNode at end
}


struct Node* createList(FILE* inf) //createList function defined
{
    if (!inf){ 
    return NULL; //NULL file pointer returns NULL
    } 

    struct Node* head = NULL;
    char fileLine[MAX_LINE_SIZE];

    while (fgets(fileLine, sizeof(fileLine), inf)) {
        fileLine[strcspn(fileLine, "\n")] = '\0'; // Remove newline
        
        struct Node* newNode = createNode(fileLine); //creates new node for each line in file
        insertAtEnd(&head, newNode); // links created node to list
    }
    return head; // return head of linked list
}

struct Node* removeNode(struct Node** head, int index) //removeNode defined
 {
    if(head == NULL){ //head is null
        return NULL;
    }
    if(*head == NULL){ // head points to null
        return NULL;
    }
    if(index < 0){ // index less than 0
        return NULL;
    }
    struct Node* start = *head; 
    struct Node* prev = NULL;

    if(index == 0){ // removing head node
        *head = start->next; //head = next node
        return start; // return removed
    }
    //traverse to index
    int i;
    for(i = 0; start != NULL && i < index; i++){
        prev = start;
        start = start->next;
    }

    if(!start){ //index out of bounds
        return NULL;
    }

    prev->next = start->next;

    return start;
}

void traverse(struct Node* head){ //traverse function defined
    struct Node* start = head;
    while (start != NULL) {
        printf("%s\n", start->data);
        start = start->next;
    }
}

void freeNode(struct Node* aNode){ //freeNode function defined
   if(aNode != NULL){
    free(aNode);
   }
    
}

void freeList(struct Node** head){ //freeList function defined
    struct Node* start;

    while (*head != NULL) {
        start = *head;
        *head = (*head)->next;
        free(start);
    }

}
