#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
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
    newNode->info = value;
    newNode->next = NULL;
    return newNode;
}

int findHighestNumber(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        exit(1);
    }
    int highest = head->info;
    Node *current = head->next;
    while (current != NULL)
    {
        if (current->info > highest)
        {
            highest = current->info;
        }
        current = current->next;
    }
    return highest;
}

int main()
{
    FILE *f = fopen("lista.txt", "r");
    if (f == NULL)
    {
        printf("File can't be opened\n");
        return 1;
    }

    Node *head = NULL, *current = NULL, *newNode;
    int temp;

    while (fscanf(f, "%d", &temp) == 1)
    {
        printf("Read number: %d\n", temp);
        newNode = loadNode(temp);
        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    if (head == NULL)
    {
        printf("No numbers were read from the file.\n");
    }
    else
    {
        int highest = findHighestNumber(head);
        printf("The highest number in the list is: %d\n", highest);
    }

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }

    fclose(f);

    return 0;
}