#include "LinkedList.h"

/*struct Node* createNode(char* data) //needs work
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //allocating mem for new node
    

    
}*/
void insertAtEnd(struct Node** head, struct Node* newNode){
    if (*head == NULL) {
        *head = newNode;
    }
   else{
    struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
   }
   
}


/*struct Node* createList(FILE* inf) needs work
{
    struct Node* head = NULL;
    char fileLine[MAX_LINE_SIZE];
    while (fgets(fileLine, sizeof(fileLine), inf)) {
        fileLine[strcspn(fileLine, "\n")] = '\0'; // Remove newline character
        struct Node* newNode = createNode(fileLine);
        insertAtEnd(&head, newNode);
    }
    return head;
}*/

/*struct Node* removeNode(struct Node** head, int index) //needs work
//{
   
}*/

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
