#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int info;
    struct Node *next;
} Node;

Node* createNode(int value);

#endif
