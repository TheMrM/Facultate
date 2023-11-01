#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void  remove(int data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    int search(int data) {
        int position = 1;
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == data) {
                return position;
            }
            current = current->next;
            position++;
        }

        return -1;
        
    }
};

int main() {
    LinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);

    myList.display();

    int searchData = 3;
    int position = myList.search(searchData);

    if (position != -1) {
        cout << "Data " << searchData << " found at position " << position << endl;
        } else {
            cout << "Data " << searchData << " not found in list " << endl;
        }
    myList.remove(3);
    myList.remove(1);
    
    myList.display();

    return 0;
}
