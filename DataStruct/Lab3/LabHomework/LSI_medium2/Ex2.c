#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int numar;
    struct Node *urmNod;
};

typedef struct Node Node;

Node *incNod(int val)
{
    Node *nouNod = (Node *)malloc(sizeof(Node));
    if (nouNod == NULL)
    {
        printf("Nu sa putut aloc memorie!\n");
        exit(1);
    }

    nouNod->numar = val;
    nouNod->urmNod = NULL;
    return nouNod;
}

void adaugaDuplicat(Node **cap, int val)
{
    Node *nouNod = incNod(val);
    nouNod->urmNod = (*cap)->urmNod;
    (*cap)->urmNod = nouNod;
    *cap = nouNod;
}

int main()
{
    FILE *f = fopen("lista2.txt", "r");
    if (f == NULL)
    {
        printf("Nu sa putut crea fisierul\n");
        return 1;
    }

    Node *cap = NULL, *current = NULL, *nouNod;
    int temp;

    while (fscanf(f, "%d", &temp) == 1)
    {
        nouNod = incNod(temp);
        if (cap == NULL)
        {
            cap = nouNod;
            current = cap;
        }
        else
        {
            current->urmNod = nouNod;
            current = nouNod;
        }
    }

    current = cap;
    Node *nextOriginal = NULL;
    while (current != NULL)
    {
        nextOriginal = current->urmNod;
        if (current->numar >= 1 && current->numar <= 9)
        {
            for (int i = 0; i < current->numar; i++)
            {
                adaugaDuplicat(&current, current->numar);
            }
        }
        current = nextOriginal;
    }

    current = cap;

    while (current != NULL)
    {
        printf("%d ", current->numar);
        Node *temp = current;
        current = current->urmNod;
        free(temp);
    }

    fclose(f);

    return 0;
}