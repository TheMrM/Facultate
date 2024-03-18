#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int info;
    struct Node *next;
};

typedef struct Node Node;
FILE *fin, *fout;
Node *head, *last;

Node *incarcaNod() {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
} 

void readList() {
    int infoValue;
    if (!head && fscanf(fin, "%d", &infoValue) == 1) {
        head = incarca_nod();
        head->info = infoValue;
        last = head;
    }

    while(fscanf(fin, "%d", &infoValue) == 1) {
        Node *newNode = incarca_nod();
        newNode->info = infoValue;
        last->next = newNode;
        last = newNode;
    }
}
