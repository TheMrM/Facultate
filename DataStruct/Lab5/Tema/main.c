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

void eliminareNoduriPanaLaUltim(struct Node **head) {
    if(!head || !*head || (*head)->next == *head) {
        return;
    }

    struct Node *current = (*head)->next;
    while (current != *head) {
        struct Node *temp = current;
        current = current->next;
        if (temp != *head) {
            free(temp);
        }
    }
    (*head)->next = *head;
}

int main() {
    int n;
    printf("How many elements do you want your list to have: :");
    scanf("%d", &n);

    struct Node* initialList = createCircularList(n);
    printf("Original list: ");
    afisareLista(initialList);

    eliminareNoduriPanaLaUltim(&initialList);
    printf("List after removals: ");
    afisareLista(initialList);

    free(initialList);

    return 0;
}
