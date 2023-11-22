#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string prenume[] = {"Andrei", "Maria", "Alexandru", "Elena", "Ion", "Ioana", "Mihai", "Andreea", "George", "Laura"};
string nume[] = {"Popa", "Popescu", "Dumitrescu", "Stan", "Stoica", "Ionescu", "Nistor", "Marin", "Tudor", "Dima"};
string ocupatie[] = {"IT Specialist","Inginer","Profesor","Vanzator","Contabil","Fermier","Antreprenor","Sudor","Farmacist","Taximetrist"};
string medicType[] = {"Cardiolog", "Neurolog", "Pediatru", "Oncolog", "Dermatolog"};
class Medic {
    string nume;
    string prenume;
    string medicType;

    public:
        Medic() {
            nume = nume[rand() % (sizeof(nume) / sizeof(string))];
            prenume = prenume[rand() % (sizeof(prenume) / sizeof(string))];
            medicType = medicType[rand() % (sizeof(medicType) / sizeof(string))];
        }
};

class Pacient {
    string nume;
    string prenume;
    string ocupatie;

    public:
        Pacient() {
            nume = nume[rand() % (sizeof(nume) / sizeof(string))];
            prenume = prenume[rand() % (sizeof(prenume) / sizeof(string))];
            ocupatie = ocupatie[rand() % (sizeof(ocupatie) / sizeof(string))];
        }
};