#include <stdio.h>
#include <stdlib.h>

struct IntNode
{
    int info;
    struct IntNode *next;
};

typedef struct IntNode IntNode;

IntNode *incarcaNod()
{
    IntNode *newNode = (IntNode *)malloc(sizeof(IntNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

int main()
{
    FILE *f = fopen("date.in", "r");
    if (f == NULL)
    {
        printf("File could not be opened\n");
        return 1;
    }

    IntNode *head = NULL, *current = NULL;
    int temp;

    if (fscanf(f, "%d", &temp) == 1)
    {
        head = incarcaNod();
        head->info = temp;
        current = head;
    }

    while (fscanf(f, "%d", &temp) == 1)
    {
        current->next = incarcaNod();
        current = current->next;
        current->info = temp;
    }

    current = head;
    while (current != NULL)
    {
        printf("%d ", current->info);
        current = current->next;
    }

    current = head;
    IntNode *tempNode;
    while (current != NULL)
    {
        tempNode = current;
        current = current->next;
        free(tempNode);
    }

    fclose(f);
    return 0;
}