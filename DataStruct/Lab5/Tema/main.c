#include <stdlib.h>
#include <stdio.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *incarca_nod(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    newNode->info = val;
    newNode->next = NULL;
    return newNode;
}

void afisareLista(struct Node *head) {
    if (!head) {
        printf("This list is empty.\n");
        return;
    }
    struct Node *current = head;
    do {
        printf("%d ", current->info);
        current = current->next;
    } while (current != head);
    printf("\n");
}

struct Node* createCircularList(int n) {
    int value;
    struct Node *head = NULL, *tail = NULL;

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);

        struct Node *newNode = incarca_nod(value);

        if(head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        } 
        tail = newNode;
    }
    if (tail != NULL) {
        tail->next = head;
    }

    return head;
}

void eliminareNoduriPanaLaUltim(struct Node **head, int m) {
    if (!head || !*head) {
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        if (current == *head) {
            *head = prev->next;
        }
        free(current);
        current = prev->next;
    }
}

int main() {
    int n, m;
    printf("How many elements do you want your list to have: ");
    scanf("%d", &n);
    printf("Enter the step count for elimination: ");
    scanf("%d", &m);

    struct Node* initialList = createCircularList(n);
    printf("Original list: ");
    afisareLista(initialList);

    eliminareNoduriPanaLaUltim(&initialList, m);
    printf("List after removals: ");
    afisareLista(initialList);

    free(initialList);

    return 0;
}
