#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Functie pentru a insera un nou nod dupa un nod dat
void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Nodul anterior nu poate fi NULL\n");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Setare date pentru noul nod
    new_node->data = new_data;
    // Legatura noului nod cu urmatorul nod
    new_node->next = prev_node->next;
    // Legatura nodului anterior cu noul nod
    prev_node->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    // Inserarea unui nou nod dupa al doilea nod
    insertAfter(second, 4);

    printList(head);

    return 0;
}