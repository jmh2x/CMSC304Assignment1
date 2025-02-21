#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Givens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node* createNode(char* data);
struct Node* createList(FILE* inf);
struct Node* removeNode(struct Node** head, int index);
void insertAtEnd(struct Node** head, struct Node* newNode);
void traverse(struct Node* head);
void freeNode(struct Node* aNode);
void freeList(struct Node** head);
#endif