#include "LinkedList.h"



struct Node* createNode(char* data)
{   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL; // Check memory allocation
    
    newNode->data = (char*)malloc(strlen(data) + 1); // Allocate memory for string
    if (!newNode->data) {
        free(newNode);
        return NULL;
    }
    strcpy(newNode->data, data); // Copy string
    newNode->next = NULL;
    return newNode;
}


void insertAtEnd(struct Node** head, struct Node* newNode){
    if (!newNode) return;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}


struct Node* createList(FILE* inf) 
{
    if (!inf) return NULL;
    struct Node* head = NULL;
    char fileLine[MAX_LINE_SIZE];
    while (fgets(fileLine, sizeof(fileLine), inf)) {
        fileLine[strcspn(fileLine, "\n")] = '\0'; // Remove newline
        struct Node* newNode = createNode(fileLine);
        insertAtEnd(&head, newNode);
    }
    return head;
}

struct Node* removeNode(struct Node** head, int index) //needs work
 {
    if (!head || !(*head) || index < 0) return NULL;
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    if (index == 0) { // Remove head
        *head = temp->next;
        return temp;
    }
    
    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (!temp) return NULL; // Index out of bounds
    prev->next = temp->next;
    return temp;
}

void traverse(struct Node* head){ //good
    struct Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

void freeNode(struct Node* aNode){ //good
    if (aNode) {
        free(aNode->data);
        free(aNode);
    }
    
}

void freeList(struct Node** head){ //good
    struct Node* current = *head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        freeNode(current);
        current = nextNode;
    }
    *head = NULL;
}
