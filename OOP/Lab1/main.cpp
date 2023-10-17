#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int age;
    int grade;
};

const int MAX_STUDENTS = 100; // Numarul maxim de studenti

// Function prototypes
bool isRollNumberUnique(const Student database[], int numStudents, int rollNumber);
bool isNameValid(const string& name); // Verifica numele sa fie compus din litere 
bool isGradeValid(int grade); // Verifica nota sa fie cuprinsa in intervalul [1, 10]
void addStudent(Student database[], int& numStudents);
void displayStudent(const Student& student);
void displayAllStudents(const Student database[], int numStudents);

int main() {
    Student studentDatabase[MAX_STUDENTS];
    int numStudents = 0;

    // Your code here (implementati meniul si functionalitatile)
    while (true) {
        cout << "Meniu Baza de Date studenti:" << endl;
        cout << "1. Adauga student" << endl;
        cout << "2. Afiseaza student" << endl;
        cout << "3. Arata toti studentii" << endl;
        cout << "4. Inchide aplicatia" << endl;
        cout << "Alege optiunea: ";

        int optiune;
        cin >> optiune;

        switch (optiune) {
        case 1:
            addStudent(studentDatabase, numStudents);
            break;
        case 2:
            if (numStudents > 0) {
                int roll;
                cout << "Introdu numarul matricol al studentului: ";
                cin >> roll;

                bool found = false;
                for (int i = 0; i < numStudents; i++) {
                    if (studentDatabase[i].rollNumber == roll) {
                        displayStudent(studentDatabase[i]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Studentul nu a fost gasit." << endl;
                }
            }
            else {
                cout << "Nici un student in baza de date." << endl;
            }
            break;
        case 3:
            if (numStudents > 0) {
                displayAllStudents(studentDatabase, numStudents);
            }
            else {
                cout << "Nici un student in baza de date." << endl;
            }
            break;
        case 4:
            cout << "Iesire din program." << endl;
            return 0;
        default:
            cout << "Optiune invalida. Alege una din optiunile valide." << endl;
        }
    }

    return 0;
}

// Function definitions

bool isRollNumberUnique(const Student database[], int numStudents, int rollNumber) {
    // Verifica numarul matricol sa nu fie duplicat, introdus deja
    for (int i = 0; i < numStudents; i++) {
        if (database[i].rollNumber == rollNumber) {
            return false; // Numar matricol nu e unicat
        }
    }
    return true; // Numar matricol e unicat
}

bool isNameValid(const string& name) {
    for (char c: name) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool isGradeValid(int grade) {
    return (grade >= 1 && grade <= 10);
}

void addStudent(Student database[], int& numStudents) {
    // Adauga student in baza de date cu numar matricol unicat
    if (numStudents < MAX_STUDENTS) {
        Student newStudent;
        
        do {
            cout << "Introdu nume student: ";
            cin.ignore();
            getline(cin, newStudent.name);
            if (newStudent.name.empty()) {
                cout << "Sectiunea nume nu poate fi goala. Introdu un nume." << endl; 
            }
            else if (!isNameValid(newStudent.name)) {
                cout << "Numele poate contine doar litere. Introdu un nume." << endl;
            }
        } while (newStudent.name.empty() || !isNameValid(newStudent.name));

        int rollNumber;
        bool uniqueRollNumber;
        do {
            cout << "Adauga numarul matricol: ";
            cin >> rollNumber;
            uniqueRollNumber = isRollNumberUnique(database, numStudents, rollNumber);
            if (!uniqueRollNumber) {
                cout << "Numarul matricol introdus exista deja. Te rugam sa introduci alt numar matricol." << endl;
            }
        } while (!uniqueRollNumber);

        newStudent.rollNumber = rollNumber;

        int age;
        do {
            cout << "Adauga varsta: ";
            cin >> age;
            if (age < 18) {
                cout << "Studentul trebuie sa fie major. Te rugam sa introduci o varsta valida." << endl;
            } 
        }   while (age < 18);

        newStudent.age = age;

        int grade;
        do {
            cout << "Adauga nota: ";
            cin >> grade;
            if (grade < 1 || grade > 10) {
                cout << "Nota trebuie sa fie intre 1 si 10. Te rugam sa introduci o nota valida." << endl;
            }
        } while (grade < 1 || grade > 10);

        newStudent.grade = grade;

        database[numStudents] = newStudent;
        numStudents++;
        cout << "Studentul adaugat in baza de date." << endl;
    }
    else {
        cout << "Numarul maxim de studenti a fost atins." << endl;
    }
}

void displayStudent(const Student& student) {
    // Implementati logica pentru a afisa un student din baza de date
    cout << "Nume: " << student.name << endl;
    cout << "Numar matricol: " << student.rollNumber << endl;
    cout << "Varsta: " << student.age << endl;
    cout << "Nota: " << student.grade << endl;
}

void displayAllStudents(const Student database[], int numStudents) {
    // Implementati logica pentru a afisa toti studentii din baza de date
    for (int i = 0; i < numStudents; i++) {
        cout << "Student numarul " << i + 1 << ":" << endl;
        displayStudent(database[i]);
        cout << "------------------------------" << endl;
    }
}