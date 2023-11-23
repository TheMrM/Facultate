#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

vector<string> names = {"Andrei", "Maria", "Alexandru", "Elena", "Ion", "Ioana", "Mihai", "Andreea", "George", "Laura"};
vector<string> surnames = {"Popa", "Popescu", "Dumitrescu", "Stan", "Stoica", "Ionescu", "Nistor", "Marin", "Tudor", "Dima"};
vector<string> occupations = {"IT Specialist","Inginer","Profesor","Vanzator","Contabil","Fermier","Antreprenor","Sudor","Farmacist","Taximetrist"};
vector<string> medicTypes = {"Cardiolog", "Neurolog", "Pediatru", "Oncolog", "Dermatolog"};

string getRandomElement(const vector<string>& vec) {
    return vec[rand() % vec.size()];
}

class Medic {
    string nume;
    string prenume;
    string medicType;

public:
    Medic() : nume(getRandomElement(surnames)), prenume(getRandomElement(names)), medicType(getRandomElement(medicTypes)) {}

    string getMedicInfo() const {
        return "Dr. " + nume + " " + prenume + ", Specializare: " + medicType;
    }
};

class Pacient {
    string nume;
    string prenume;
    string ocupatie;

public:
    Pacient() : nume(getRandomElement(surnames)), prenume(getRandomElement(names)), ocupatie(getRandomElement(occupations)) {}

    string getPacientInfo() const {
        return "Pacient " + nume + " " + prenume + ", Ocupatia: " + ocupatie;
    }
};

int main() {
    srand(time(NULL));

    Medic doctor1;
    cout << doctor1.getMedicInfo() << endl;

    Pacient pacient1;
    cout << pacient1.getPacientInfo() << endl;

    return 0;
}