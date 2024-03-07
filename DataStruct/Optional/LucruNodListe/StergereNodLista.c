#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Functie pentru stergerea unui nod dupa valoarea sa
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    // Verificam daca nodul ce trebuie sters este capul listei
    if (temp != NULL && temp->data == key)
    {
        // Schimbam capul listei
        *head_ref = temp->next;
        // Eliberam memoria nodului vechi
        free(temp);
        return;
    }

    // Cautam nodul ce trebuie sters, pastrand umra nodului anterior
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // Daca nodul nu a fost gasit in lista
    if (temp == NULL)
        return;

    // Stergem nodul din lista
    prev->next = temp->next;

    // Eliberam meroria nodului sters
    free(temp);
}

// Functia pentru afisarea listei
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

    // Alocam memorie pentru noduri
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Initializam nodurile lisei
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    // Aifsam lista inainte de stergere
    printf("Lista inainte de stergere: ");
    printList(head);

    // Stergem nodul cu valoarea 2
    deleteNode(&head, 2);

    // Afisam lista dupa stergere
    printf("\nLista dupa stergere: ");
    printList(head);

    return 0;
}