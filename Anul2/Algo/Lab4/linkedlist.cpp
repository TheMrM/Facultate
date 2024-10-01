#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void Inserare(Node* cursor, int info);
    void Stergere(Node* cursor, int* info);
    Node* Parcurgere(int info);
    void Afisare();
};

void LinkedList::Inserare(Node* cursor, int info) {
    Node* newNode = new Node(info);
    if (cursor == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

void LinkedList::Stergere(Node* cursor, int* info) {
    if (head == nullptr) return;

    Node* toDelete;
    if (cursor == nullptr) {
        toDelete = head;
        head = head->next;
    } else {
        if (cursor->next == nullptr) return;
        toDelete = cursor->next;
        cursor->next = cursor->next->next;
    }

    *info = toDelete->data;
    delete toDelete;
}

Node* LinkedList::Parcurgere(int info) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == info)
            return current;
        current = current->next;
    }
    return nullptr;
}

void LinkedList::Afisare() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    LinkedList lista;
    srand(time(nullptr));

    for (int i = 0; i < 10; i++) {
        int numarAleatoriu = rand() % 100;
        lista.Inserare(lista.head, numarAleatoriu);
    }

    cout << "Lista dupa inserarea numerelor aleatorii: ";
    lista.Afisare();

    int info;
    lista.Stergere(nullptr, &info);
    cout << "Nodul sters are valoarea: " << info << endl;
    lista.Afisare();

    Node* found = lista.Parcurgere(10);
    if (found != nullptr) {
        cout << "Nodul gasit are valoarea: " << found->data << endl;
    } else {
        cout << "Nodul nu a fost gasit." << endl;
    }

    return 0;
}