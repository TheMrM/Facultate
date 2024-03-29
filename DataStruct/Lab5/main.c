#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
    struct Node *prev;
};

struct Node *incarca_nod(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    newNode->info = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void citireLista(struct Node **head, struct Node **tail) {
    FILE *file = fopen("list.in", "r");
    if (!file) {
        fprintf(stderr, "Failed to open file list.in for reading.\n");
        exit(EXIT_FAILURE);
    }

    int valInfo;
    while (fscanf(file, "%d", &valInfo) == 1) {
        struct Node *newNode = incarca_nod(valInfo);
        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
        } else {
            (*tail)->next = newNode;
            newNode->prev = *tail;
            *tail = newNode;
        }
    }
    fclose(file);
}

void afisareLista(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

void inserareInceput(struct Node **head, int val) {
    struct Node *newNode = incarca_nod(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        newNode->next = *head;
        *head = newNode;
    }
};

void inserareSfarsit(struct Node **tail, int val) {
    struct Node *newNode = incarca_nod(val);
    if (*tail == NULL) {
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
};

void inserareLista(struct Node **head,struct Node **tail, int pozitie, int val) {
    struct Node *newNode = incarca_nod(val);
    if (*head == NULL || pozitie <= 0) {
        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
        } else {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        }
    } else {
        struct Node *current = *head;
        for (int i = 0; current != NULL && i < pozitie - 1; i++) {
            current = current->next;
        }

        if (current != NULL) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {
                current->next->prev = newNode;
            } else {
                *tail = newNode;
            }
            current->next = newNode;
        } else {
            (*tail)->next = newNode;
            newNode->prev = *tail;
            *tail = newNode;
        }
    }
};

int gasestePozitie(struct Node *head, int val) {
    int pos = 1;
    struct Node *current = head;
    while (current != NULL) {
        if (current->info == val) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

int main() {
    struct Node *head = NULL, *tail = NULL;

    citireLista(&head, &tail);
    afisareLista(head);

    inserareInceput(&head, 3);
    inserareInceput(&head, 8);
    inserareInceput(&head, 9);

    afisareLista(head);

    inserareSfarsit(&tail, 0);
    inserareSfarsit(&tail, 0);
    inserareSfarsit(&tail, 0);

    afisareLista(head);

    int locatia93 = gasestePozitie(head, 93);
    if (locatia93 != -1) {
        inserareLista(&head, &tail,locatia93, 15);
    }

    afisareLista(head);

    return 0;
}
