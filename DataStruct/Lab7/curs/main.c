#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct clasaElevi {  // 'typedef struct', not 'typedef'
    char nume[20];
    char prenume[20];
    float note[3];
    struct clasaElevi *next;
} clasaElevi;

clasaElevi* createStudent(char *nume, char *prenume, float note[]) {
    clasaElevi *newStudente = (clasaElevi*) malloc(sizeof(clasaElevi));

    if (newStudente == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    strcpy(newStudente->nume, nume);
    strcpy(newStudente->prenume, prenume);
    for (int i = 0; i < 3; i++) {
        newStudente->note[i] = note[i];
    }
    newStudente->next = NULL;
    return newStudente;
}

void addStudentEndList(clasaElevi **head, char *nume, char *prenume, float note[]) {
    clasaElevi *newStudente = createStudent(nume, prenume, note);
    if (*head == NULL) {
        *head = newStudente;
    } else {
        clasaElevi *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudente;
    }
}

void showStudents(clasaElevi *head) {
    clasaElevi *current = head;
    while (current != NULL) {
        printf("Nume: %s, Prenume: %s, Note: %.2f, %.2f, %.2f\n",
            current->nume, current->prenume,
            current->note[0], current->note[1], current->note[2]);
        current =  current->next;
    }
}

int main() {
    clasaElevi *head = NULL;
    float note1[3] = {3.6, 9.4, 8.7};
    float note2[3] = {9.1, 8.1, 8.8};

    addStudentEndList(&head, "Mihai", "Dumitru", note1);
    addStudentEndList(&head, "Ioan", "Marian", note2);

    showStudents(head);

    return 0;
}

