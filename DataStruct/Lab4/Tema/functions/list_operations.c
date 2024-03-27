#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void stergeMinMax(Node **head) {
    if (*head == NULL) {
        printf("Lista e goala\n");
        return;
    }

    int min = findMinValue(*head);
    int max = findMaxValue(*head);

    void deleteValue(Node **head, int value) {
        Node *current = *head, *prev = NULL;
        while (current != NULL) {
            if (current->info == value) {
                Node *temp = current;
                if (prev == NULL) {
                    *head = current->next;
                } else {
                    prev->next = current->next;
                }
                current = current->next;
                free(temp);
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    deleteValue(head, min);
    deleteValue(head, max);
}

int findMinValue(Node *head) {
    int lowest = head->info;
    Node *current = head->next;
    while (current != NULL) {
        if (current->info < lowest) {
            lowest = current->info;
        }
        current = current->next;
    }
    return lowest;
}

int findMaxValue(Node *head) {
    int highest = head->info;
    Node *current = head->next;
    while (current != NULL) {
        if (current->info > highest) {
            highest = current->info;
        }
        current = current->next;
    }
    return highest;
}


int isPrime(int num) {
    if(num <= 1) return 0;
    if(num <= 3) return 1;
    if(num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i +2) ==0) return 0;
    }
    return 1;
}

void insertAfter(Node* current, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Nu sa putut aloca memorie\n");
        exit(1);
    }
    newNode->info = value;
    newNode->next = current->next;
    current->next = newNode;
}

void insertAfterPrime(Node **head) {
    Node *current = *head;
    while (current != NULL && current->next != NULL) {
        if (isPrime(current->info)) {
            insertAfter(current, current->info);
            current = current->next;
        }
        current = current->next;
    }
}


void insertBefore(Node** head, Node* prev, Node* current, int value) {
    Node* newNode = createNode(value);
    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

void insertBeforeEvenNumber(Node **head) {
    Node* current = *head, *prev = NULL;
    while (current != NULL) {
        if (current->info % 2 == 0) {
            insertBefore(head, prev, current, current->info - 1);
            Node* insertNode = (prev == NULL) ? * head : prev->next;
            prev = insertNode;
            current = insertNode->next;
    } else {
        prev = current;
        current = current->next;
    }
}

int promptUserChoice() {
    int choice;
    printf("Selectati o optiune:\n");
    printf("1. Citeste numarul dintr-un fisier\n");
    printf("2. Scrie numerele din lista de la tastatura\n");
    printf("Alege optiune (1 sau 2): \n");
    scanf("%d", &choice);
    while (choice != 1 && choice != 2) {
        printf("Optiune invalida. Alege intre 1 sau 2: ");
        scanf("%d", &choice);
    }
    return choice;
}

void readOrInputList() {
    int choice = promptUserChoice();
    int numbers[10];
    int count = 0;

    if(choice == 1) {
        char filename[100];
        printf("Introdu numele fisierului (cu extensie): ");
        scanf("%s", filename);
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Fisierul nu sa putut deschide.\n");
            return;
        }
        while (count < 10 && fscanf(file, "%d", &numbers[count]) == 1) {
            count++;
        }
        fclose(file);
    } else {
        printf("Introdu 10 numbere (apasa orice tasta non numberica pentru oprire): \n");
        while (count < 10 && scanf("%d", &numbers[count]) == 1) {
            count++;
        } 
        while (getchar() != '\n');
    }
    printf("Citire number/intoduse:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }
}
