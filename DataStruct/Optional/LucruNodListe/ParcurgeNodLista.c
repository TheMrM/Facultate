#include <stdio.h>
#include <stdlib.h>

// Definim structura unui no
struct Node
{
    int data;
    struct Node *next;
};

// Functie pentru afisare toate valorile a nodurilor listei
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d", n->data);
        n = n->next; // Mergem la urmatorul nod
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Alocam memorie pentru noduri
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Asignam val pentru primul nod
    head->data = 1;
    // Legatura intre prim nod si al doile
    head->next = second;
    // Asignam val pentru al 2-lea nod
    second->data = 2;
    // Legatura intre al 2-lea si ultimul nod
    second->next = third;
    // Asignam val pentru ultimu nod
    third->data = 3;
    // Ultim nod este NULL
    third->next = NULL;

    printList(head);

    return 0;
}