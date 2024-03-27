#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->info = value;
    newNode->next = NULL;
    return newNode;
}
