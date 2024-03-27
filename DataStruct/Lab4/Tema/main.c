#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* readLinkedListFromFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    Node* head = NULL;
    Node* current = NULL;
    
    int value;
    while (fscanf(file, "%d", &value) == 1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;
    }
    
    fclose(file);
    return head;
}

Node* createLinkedListFromUserInput() {
    int n, value;
    printf("Enter number of elements in range 6 - 10: ");
    scanf("%d", &n);

    if (n < 6 || n > 10) {
        printf("Invalid number of elements. Exiting.\n");
        return NULL;
    }

    Node* head = NULL;
    Node* current = NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;
    }
    return head;
}

Node* removeByValue(Node* head, int value, int* removePosition) {
    if (head == NULL) {
        *removePosition = -1;
        return NULL; // If the list is empty, do nothing
    }

    Node* current = head;
    Node* previous = NULL;
    int position = 1;

    while (current != NULL) {
        if (current->data == value) { // Check if current node contains the value to remove
            if (previous == NULL) {
                // The node to remove is the head
                head = current->next; // Update the head of the list
            } else {
                // The node to remove is not the head
                previous->next = current->next; // Bypass the current node
            }
            free(current); // Free the removed node
            *removePosition = position;
            return head; // Return the possibly new head of the list
        }
        previous = current; // Move previous to current
        current = current->next; // Move current to the next node
        position++;
    }

    *removePosition = -1;
    return head; // Return the head (unchanged if the value was not found)
}

void findAndRemoveExtremes(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    int min = (*head)->data;
    int max = (*head)->data;
    Node* current = *head;

    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }

    int removePositionMin, removePositionMax;

    if (min != max) {
        *head = removeByValue(*head, min, &removePositionMin);
        printf("Removed lowest element %d at position %d.\n", min, removePositionMin);
        *head = removeByValue(*head, max, &removePositionMax);
        printf("Removed highest element %d at position %d.\n", max, removePositionMax);
    } else {
        *head = removeByValue(*head, min, &removePositionMin);
        printf("Removed element %d (both highest and lowest) at position %d.\n", min, removePositionMin);
    }
}


int isPrime(int number) {
    if (number <= 1) return 0; // 0 and 1 are not prime
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return 0; // Found a divisor, not prime
    }
    return 1; // Prime
}


void insertAfter(Node* prevNode, int newValue) {
    if (prevNode == NULL) return; // Can't insert after a NULL node

    Node* newNode = (Node*)malloc(sizeof(Node)); // Correctly named newNode
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return; // Always check for NULL after malloc
    }
    newNode->data = newValue; // Use newValue, the corrected parameter name
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}


void insertAfterPrime(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (isPrime(current->data)) {
            insertAfter(current, current->data); // Insert a new node with the same value
            current = current->next; // Move past the new node to avoid infinite loop
        }
        current = current->next; // Proceed to the next original node
    }
}

void printList(Node* head, int showAnnotations) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        printf("Node %d: %d (position %d", position, current->data, position);

        if (showAnnotations) {
            if (isPrime(current->data)) {
                printf(", primeNumber");
            }
            if (current->next != NULL && current->data == current->next->data) {
                printf(", insertedAfterPrime");
            }
            if (current->prev != NULL && current->data % 2 == 0 && current->prev->data == current->data - 1) {
                printf(", previousIs2k-1");
            }
            if (current->data % 2 == 0) {
                printf(", evenNumber");
            }
        }

        printf(")\n");
        current = current->next;
        position++;
    }
}

void printListWithPrimes(Node* head) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        printf("Node %d: %d (position %d", position, current->data, position);

        // Check if the current node is a prime number
        if (isPrime(current->data)) {
            printf(", primeNumber");
        }

        printf(")\n"); // Close the parentheses

        current = current->next; // Move to the next node
        position++;
    }
}

void printListBeforeInsertingBeforeEven(Node* head) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        printf("Node %d: %d (position %d", position, current->data, position);

        // Check if the current node is an even number
        if (current->data % 2 == 0) {
            // Print the value that will be inserted before the even number
            printf(", we will insert: %d", current->data - 1);
        }

        printf(")\n"); // Close the parentheses

        current = current->next; // Move to the next node
        position++;
    }
}

Node* copyList(Node* head) {
    Node* newHead = NULL; // Declare newHead at the beginning of the function
    Node* current = head;
    Node** tail = &newHead;

    while (current != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            perror("Failed to allocate memory for new node");
            // Ideally, you should also free the partially created new list before returning
            while (newHead != NULL) {
                Node* temp = newHead;
                newHead = newHead->next;
                free(temp);
            }
            return NULL;
        }
        newNode->data = current->data; // Copy data
        newNode->next = NULL; // Next is NULL initially

        *tail = newNode; // Append newNode to the end of the new list
        tail = &newNode->next; // Update tail to point to the last node's next pointer

        current = current->next; // Move to next node in the original list
    }

    return newHead;
}

void insertBeforeEvenElements(Node** head) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data % 2 == 0) { // Check if current node is even
            int newValue = current->data - 1; // Calculate newValue as current->data - 1

            if (prev == NULL || prev->data != newValue) { // Ensure no duplicate insertion
                Node* newNode = (Node*)malloc(sizeof(Node));
                if (newNode == NULL) {
                    perror("Failed to allocate memory for newNode");
                    exit(EXIT_FAILURE);
                }
                newNode->data = newValue; // Set newNode's data
                newNode->next = current; // Link newNode to current

                if (prev == NULL) {
                    *head = newNode; // Update head if inserting at the beginning
                } else {
                    prev->next = newNode; // Link prev to newNode
                }
                prev = newNode; // Update prev to point to newNode
            }
        }
        prev = current; // Update prev to current
        current = current->next; // Move to the next node
    }
}

int main() {
    int choice;
    printf("Enter 1 to load the linked list from a file or 2 to create a new list with a range between 6-10 elements: ");
    scanf("%d", &choice);

    Node* originalList = NULL;
    Node* modifiedList1 = NULL;
    Node* modifiedList2 = NULL;

    if (choice == 1) {
        const char* filePath = "data.in";
        originalList = readLinkedListFromFile(filePath);
    } else if (choice == 2) {
        originalList = createLinkedListFromUserInput();
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    modifiedList1 = copyList(originalList);
    modifiedList2 = copyList(originalList);

    // Case 1: List containing prime numbers
    printf("List containing prime numbers:\n");
    printList(originalList, 0); // Print the original list
    findAndRemoveExtremes(&originalList); // Remove the highest and lowest elements
    printf("\nList after removing the highest and lowest elements:\n");
    printList(originalList, 0); // Print the modified list without annotations

    // Case 2: List after inserting a copy of prime numbers after each prime number
    printf("\nSecond linked list with prime number:\n");
    printListWithPrimes(modifiedList1); // Print the list with prime numbers annotated
    insertAfterPrime(modifiedList1); // Insert a copy of prime numbers after each prime number
    printf("\nLinked list after we insert duplicate of prime numbers:\n");
    printListWithPrimes(modifiedList1); // Print the modified list with annotations

    // Case 3: List after subtracting 1 from even elements and inserting before even elements
    printf("\nLinked list with even elements:\n");
    printListBeforeInsertingBeforeEven(modifiedList2); // Print the list before modification
    insertBeforeEvenElements(&modifiedList2); // Subtract 1 from even elements and insert before even elements
    printf("\nLinked list when we insert before even elements the 2k-1:\n");
    printListBeforeInsertingBeforeEven(modifiedList2); // Print the modified list with annotations
    
    return 0;
}
