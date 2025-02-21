#include "LinkedList.h"

struct Node* createNode(char* data)
{   struct Node* newNode = NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //allocating mem for new node
    if (newNode == NULL)
    {
        return NULL;
    }
   /* else{
    newNode->data = data;
    newNode->next = NULL;
    
      return newNode;
    }*/
    newNode->data = (char*)malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        return NULL;
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, struct Node* newNode){
    if (head == NULL || newNode == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = newNode;
         return;
    }
   else{
    struct Node* lastNode = *head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        return;
    }

   
}


struct Node* createList(FILE* inf) 
{
    struct Node* head = NULL;
    char fileLine[MAX_LINE_SIZE];
    while (fgets(fileLine, sizeof(fileLine), inf)) {
        fileLine[strcspn(fileLine, "\n")] = '\0'; // Remove newline character
        struct Node* newNode = createNode(fileLine);
        insertAtEnd(&head, newNode);
    }
    return head;
}

struct Node* removeNode(struct Node** head, int index) //needs work
 {
    if (head == NULL || *head == NULL || index < 0) {
        return NULL;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    // If the node to be removed is the head node
    if (index == 0) {
        *head = current->next;
        current->next = NULL;
        return current;
    }
    // If the index is out of bounds
    if (current == NULL) {
        return NULL;
    }

    // Traverse the list to find the node at the given index
    for (int i = 0; current != NULL && i < index; i++) {
        previous = current;
        current = current->next;
    }

    
    // Remove the node
    previous->next = current->next;
    current->next = NULL;

    return current;
}

void traverse(struct Node* head){ //good
    struct Node* current = head;
    while (current != NULL) {
        current = current->next;
        printf("%d\n", current->data);
    }
}

void freeNode(struct Node* aNode){ //good
    if (aNode != NULL) {
        free(aNode->data); // Free the allocated data
        free(aNode); // Free the node itself
    }
    
}

void freeList(struct Node** head){ //good
    struct Node* current = *head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current = nextNode;
        freeNode(current);
    }

    *head = NULL;
}
