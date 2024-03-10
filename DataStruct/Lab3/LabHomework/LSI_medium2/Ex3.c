#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int numar;
    struct Node *urmNod;
};

typedef struct Node Node;

Node *loadNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Failed to allocate memory!\n");
        exit(1);
    }

    newNode->numar = value;
    newNode->urmNod = NULL;
    return newNode;
}

void findHighestAndLowest(Node *head, int *highest, int *lowest)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        exit(1);
    }
    *highest = head->numar;
    *lowest = head->numar;

    Node *current = head->urmNod;
    while (current != NULL)
    {
        if (current->numar > *highest)
        {
            *highest = current->numar;
        }
        if (current->numar < *lowest)
        {
            *lowest = current->numar;
        }
        current = current->urmNod;
    }
}

int main()
{
    FILE *f = fopen("lista3.txt", "r");
    if (f == NULL)
    {
        printf("File can't open\n");
        return 1;
    }

    Node *head = NULL, *current = NULL;
    int temp;

    while (fscanf(f, "%d", &temp) == 1)
    {
        Node *newNode = loadNode(temp);
        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->urmNod = newNode;
            current = newNode;
        }
    }

    int highest, lowest;
    findHighestAndLowest(head, &highest, &lowest);

    if (head != NULL)
    {
        printf("The highest number in the linked list is: %d\n", highest);
        printf("The lowest number in the linked list is %d\n", lowest);
    }

    while (head != NULL)
    {
        Node *tempNode = head;
        head = head->urmNod;
        free(tempNode);
    }

    fclose(f);
    return 0;
}