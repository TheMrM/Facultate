#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct StackNode {
    int info;
    struct StackNode *link;
};

typedef struct StackNode StackNode;

StackNode *createStackNode();
void push(StackNode **top, int value);
int pop(StackNode **top);
void display(StackNode *top);
void freeStack(StackNode *top);
void readInput(int *N, int *K, StackNode **top);
void calculatePrefixSum(int *stackArray, int N, int *prefixStack, int *prefixQueue);
int computeMaxSum(int K, int N, int *prefixStack, int *prefixQueue, int *elementsRemoved);
void rebuildAndDisplayStack(int *stack, int N, int *keep, int K);
void printRemovedElements(int *stackArray, int *elementsRemoved, int K);
void cleanUp(int *stackArray, int *prefixStack, int *prefixQueue);

int main() {
    int N, K;
    StackNode *top = NULL;

    readInput(&N, &K, &top);

    int *stackArray = (int *)malloc(N * sizeof(int));
    if (stackArray == NULL) {
        fprintf(stderr, "Failed to allocate memory for stack array.\n");
        return EXIT_FAILURE;
    }

    for (int i = N - 1; i >= 0; i--) {
        stackArray[i] = pop(&top);
    }

    int *prefixStack = (int *)calloc(N + 1, sizeof(int));
    int *prefixQueue = (int *)calloc(N + 1, sizeof(int));
    calculatePrefixSum(stackArray, N, prefixStack, prefixQueue);

    int *elementsRemoved = (int *)calloc(K, sizeof(int));
    int maxSum = computeMaxSum(K, N, prefixStack, prefixQueue, elementsRemoved);
    printf("Maximum sum possible of the removed elements: %d\n", maxSum);
    printRemovedElements(stackArray, elementsRemoved, K);

    int keep[N];
    memset(keep, 1, sizeof(keep));
    for (int i = 0; i < K; i++) {
        keep[elementsRemoved[i]] = 0;
    }
    rebuildAndDisplayStack(stackArray, N, keep, K);

    cleanUp(stackArray, prefixStack, prefixQueue);
    free(elementsRemoved);
    return 0;
}

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
}

int pop(StackNode **top) {
    if (*top == NULL) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    StackNode *temp = *top;
    *top = (*top)->link;
    int value = temp->info;
    free(temp);
    return value;
}

void readInput(int *N, int *K, StackNode **top) {
    scanf("%d %d", N, K);
    for (int i = 0; i < *N; i++) {
        int value;
        scanf("%d", &value);
        push(top, value);
    }
}

void calculatePrefixSum(int *stackArray, int N, int *prefixStack, int *prefixQueue) {
    for (int i = 1; i <= N; i++) {
        prefixStack[i] = prefixStack[i - 1] + stackArray[i - 1];
        prefixQueue[i] = prefixQueue[i - 1] + stackArray[N - i];
    }
}

int computeMaxSum(int K, int N, int *prefixStack, int *prefixQueue, int *elementsRemoved) {
    int maxSum = 0, bestSplit = 0;
    for (int i = 0; i <= K; i++) {
        if (i <= N && K - i <= N) {
            int currentSum = prefixStack[i] + prefixQueue[K - i];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestSplit = i;
            }
        }
    }

    for (int i = 0; i < bestSplit; i++) {
        elementsRemoved[i] = i; // indices from the stack
    }
    for (int i = 0; i < K - bestSplit; i++) {
        elementsRemoved[bestSplit + i] = N - 1 - i; // indices from the queue
    }

    return maxSum;
}

void printRemovedElements(int *stackArray, int *elementsRemoved, int K) {
    printf("Removed elements contributing to max sum: ");
    for (int i = 0; i < K; i++) {
        printf("%d ", stackArray[elementsRemoved[i]]);
    }
    printf("\n");
}

void display(StackNode *top) {
    while (top != NULL) {
        printf("%d ", top->info);
        top = top->link;
    }
    printf("\n");
}

void freeStack(StackNode *top) {
    StackNode *current = top;
    while (current != NULL) {
        StackNode *next = current->link;
        free(current);
        current = next;
    }
}

void rebuildAndDisplayStack(int *stack, int N, int *keep, int K) {
    StackNode *newTop = NULL;

    for (int i = N - 1; i >= 0; i--) {
        if (keep[i]) {
            push(&newTop, stack[i]);
        }
    }
    printf("Stack after removing elements for max sum:\n");
    display(newTop);
    freeStack(newTop);
}

void cleanUp(int *stackArray, int *prefixStack, int *prefixQueue) {
    free(stackArray);
    free(prefixStack);
    free(prefixQueue);
}
