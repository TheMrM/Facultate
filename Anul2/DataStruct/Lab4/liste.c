#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>

struct Node {
    int info;
    struct Node *next;
};

typedef struct Node Node;

FILE *fin, *fout;
Node *head, *last;

Node *incarca_nod() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n"); 
        exit(EXIT_FAILURE);
    }
    newNode->info = 0;
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

void inserarePrim() {
    Node *newNode = incarca_node();
    printf("Enter the value for the new node: ");
    scanf("%d", &newNode->info);
    newNode->next = head;
    head = newNode;
}
    
void inserareUltim() {
    if (head == NULL) {
    inserarePrim();
    return;
    }
    Node *newNode = incarca_node();
    printf("Enter the value for the new node: ");
    scanf("%d", &newNode->info);
    last->next = newNode;
    last = newNode;
}

void inserare_dupa_nod(int valoare) {
    Node *current = head;
    while (current != NULL && current->info != valoare)
        current = current->next;
    if (current) {
        Node *newNode = incarca_nod();
        printf("Enter the value of the new node");
        scanf("%d", &newNode->info);

        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Value not found.\n");
    }
}

void printList() {
    fout = fopen("data.out", "w");
    if (!fout) {
        fprintf(stderr, "fopen() failed in file %s!!!\n", __FILE__);
        exit(EXIT_FAILURE);
    }
    Node *current = head;
    while (current) {
        fprintf(fout, "%d", current->info);
        current = current->next;
    }
    fprintf(fout, "\n");
    fclose(fout);

}

int main() {
    fin = fopen("data.in", "r");
    if (!fin) {
        fprintf(stderr, "fopen() failed in file %s!!!\n", __FILE__);
        exit(EXIT_FAILURE);
    }

    fclose(fin);
    return 0;
}
