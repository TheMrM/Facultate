#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->head = q->tail = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = newNode;
        return;
    }

    q->tail->next = newNode;
    q->tail = newNode;
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        fprintf(stderr, "Queue underflow\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = q->head;
    int value = temp->data;
    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return value;
}

void displayQueue(Queue* q) {
    Node* current = q->head;
    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("After enqueue operations:\n");
    displayQueue(q);

    printf("Dequeue: %d\n", dequeue(q));

    printf("After dequeue operations:\n");
    displayQueue(q);

    while (q->head != NULL) {
        dequeue(q);
    }
    free(q);

    return EXIT_SUCCESS;
}
