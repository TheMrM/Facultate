#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int info;
    struct StackNode *link;
};

typedef struct StackNode StackNode;

StackNode *createStackNode() {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->link = NULL;
    return node;
}


void push(StackNode **top, int value) {
    StackNode *newNode = createStackNode(); 
    newNode->info = value;
    newNode->link = *top;
    *top = newNode;
    return;
}

int pop(StackNode **top){
    if (*top == NULL) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    StackNode *temp = *top;
    *top = (*top)->link;
    int x = temp->info;
    free(temp);
    return x;
}

void display(StackNode *top) {
    printf("Stack contents:\n");
    while (top != NULL) {
        printf("%d\n", top->info);
        top = top->link;
    }
}

int main() {
    
    StackNode *top = NULL;

    FILE *f = fopen("date.in", "r");

    if (f == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    int x;
    while(fscanf(f, "%d", &x) == 1) {
        push(&top, x);
    }

    fclose(f);

    printf("Initial stack:\n");
    display(top);

    printf("\nPopping one element...\n");
    pop(&top);

    printf("Stack after modifications:\n");
    display(top);

    while (top != NULL) {
        pop(&top);
    }


    return EXIT_SUCCESS;
}

