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

class Pacient {
    string nume;
    string prenume;
    string ocupatie;
    int varsta;

public:
    Pacient() : nume(getRandomElement(surnames)), prenume(getRandomElement(names)), ocupatie(getRandomElement(occupations)), varsta(rand() % 67 + 4) {
        if (varsta < 18) {
            ocupatie = "Elev";
        } else if (varsta < 55){
            ocupatie = getRandomElement(occupations);
        } else if (varsta >= 55){
            ocupatie = "Pensionar";
        }
    }

    string getPacientInfo() const {
        return "Pacient " + nume + " " + prenume + " in varsta de " + to_string(varsta) + " ani, Ocupatia: " + ocupatie;
    }

    int getVarsta() const {
        return varsta;
    }
};
class Medic {
    string nume;
    string prenume;
    string medicType;
    vector<Pacient> pacienti;

public:
    Medic() : nume(getRandomElement(surnames)), prenume(getRandomElement(names)), medicType(getRandomElement(medicTypes)) {
        int numarPacienti = rand() % 10 + 1;
        for (int i = 0; i < numarPacienti; ++i) {
            pacienti.push_back(Pacient());
        }
    }

    string getMedicInfo() const {
        string info = "Dr. " + nume + " " + prenume + "\nSpecializare: " + medicType;
        info += "\nNumar Pacienti: " + to_string(pacienti.size());
        return info;
    }

    void afiseazaInfoPacienti() const {
        for (const auto& pacient : pacienti) {
            cout << pacient.getPacientInfo() << endl;
        }
    }

    int numarPacientiSub18() const {
        int count = 0;
        for (const auto& pacient : pacienti) {
            if (pacient.getVarsta() < 18) {
                count++;
            }
        }

        return count;
    }

    int numarPacientiPensionari() const {
        int count = 0;
        for (const auto& pacient : pacienti) {
            if (pacient.getVarsta() >= 55) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    srand(time(NULL));

    int numarDoctori = rand() % 5 + 1;
    vector<Medic> doctori;

    for (int i = 0; i < numarDoctori; i++) {
        doctori.push_back(Medic());
    }

    for (int i = 0; i < numarDoctori; ++i) {
        cout << "Doctor " << (i + 1) << " : " << endl;
        cout << doctori[i].getMedicInfo() << endl;

        int pacientiMinori = doctori[i].numarPacientiSub18();
        cout << "Numarul de pacienti sub 18 ani: " << pacientiMinori << endl;

        int pacientiPensionari = doctori[i].numarPacientiPensionari();
        cout << "Numarul de pacienti pensionari: " << pacientiPensionari << endl;

        cout << "Lista cu pacienti: " << endl;
        doctori[i].afiseazaInfoPacienti();
        cout << endl;
    }

    return 0;
}