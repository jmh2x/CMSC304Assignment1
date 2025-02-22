#include "Testing.h"
int main(){

    //initialize file pointer to NULL 
    FILE *infile = NULL; 
    //Define a character array to store the name of the file to read and write
    char filename[MAX_LINE_SIZE];  
    //Prompt the user to input a filename and continue to prompt the user until they enter a correct one
    while(infile == NULL) {  
        printf("Enter filename: ");  
        scanf("%s",filename);
        //When given a filename, use fopen to create a new file pointer. 
            //If fopen can not find the file, it returns null
        infile = fopen(filename, "r+");
        if(infile == NULL){ 
            printf("ERROR: file %s cannot be opened\n", filename);
        }
    }

    //Test your linked list functions here!!!
    struct Node* head = NULL;

    // Test createNode
    struct Node* node1 = createNode("Node 1");
    struct Node* node2 = createNode("Node 2");
    struct Node* node3 = createNode("Node 3");

    // Check if nodes are created successfully
    if (node1 != NULL) {
        printf("Node 1 created with data: %s\n", node1->data);
    } else {
        printf("Failed to create Node 1\n");
    }

    if (node2 != NULL) {
        printf("Node 2 created with data: %s\n", node2->data);
    } else {
        printf("Failed to create Node 2\n");
    }

    if (node3 != NULL) {
        printf("Node 3 created with data: %s\n", node3->data);
    } else {
        printf("Failed to create Node 3\n");
    }

    // Test insertAtEnd
    insertAtEnd(&head, node1);
    insertAtEnd(&head, node2);
    insertAtEnd(&head, node3);

    // Test traverse
    printf("Linked List after insertion:\n");
    traverse(head);

    // Test removeNode
    struct Node* removedNode = removeNode(&head, 1);
    if (removedNode != NULL) {
        printf("Removed Node: %s\n", removedNode->data);
        freeNode(removedNode);
    }

    // Test traverse after removal
    printf("Linked List after removal:\n");
    traverse(head);

    // Test createList
    struct Node* fileList = createList(infile);
    printf("Linked List created from file:\n");
    traverse(fileList);

    // Free the lists
    freeList(&head);
    freeList(&fileList);

    fclose(infile);

}
