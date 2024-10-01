#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Biblioteca {
    string oras;
    string judet;
    string strada;
    int numar;
};

class Carte {
    string titlu;
    string autor;
    int numarInventar;
public:
    Carte(string t, string a, int num) : titlu(t), autor(a), numarInventar(num) {}
    string getTitlu() const { return titlu; }
    string getAutor() const { return autor; }
    int getNumarInventar() const { return numarInventar; }
};

class Cititor {
    string Nume;
    string Prenume;
public:
    Cititor(string n, string p) : Nume(n), Prenume(p) {}
    string getNume() const { return Nume; }
    string getPrenume() const { return Prenume; }
    string getNumePrenume() const { return Nume + " " + Prenume; }
};

class Imprumut {
    Cititor* cititor;
    Carte* carte;
    string dataImprumut;
    string dataRetur;
public:
    string getDataRetur() const { return dataRetur; }
    vector<Imprumut> extrageImprumuturiDepasite(vector<Imprumut>& imprumuturi, const string& dataCurenta) {}
    int getDurata() const {
        return 0;
    }
};

class Catalog {
    vector<Carte*> carti;
public:
    void adaugaCarte(Carte* carte) {
        carti.push_back(carte);
    }

    const vector<Carte*>& getCarti() const { return carti; }
};

class ManagerBibiloteca {
    Biblioteca* biblioteca;
    Catalog* catalog;
    vector<Imprumut> imprumuturi;
public:
    ManagerBibiloteca(Biblioteca* bib) : biblioteca(bib) {}
};

bool depasesteDataRetur(const Imprumut& imprumut, const string& dataCruenta) {

    return imprumut.getDataRetur() < dataCruenta;
}

vector<Imprumut> extrageImprumuturiDepasite(vector<Imprumut>& imprumuturi, const string& dataCurenta) {
    vector<Imprumut> rezultat;
    for (const auto& imprumut : imprumuturi) {
        if (depasesteDataRetur(imprumut, dataCurenta)) {
            rezultat.push_back(imprumut);
        }
    }
    return rezultat;
}

Imprumut imprumutMaxDurata(vector<Imprumut>& imprumuturi) {
    if (imprumuturi.empty()) {
        throw runtime_error("Nu sunt imprumuturi pentru a compara");
    }
    return *max_element(begin(imprumuturi), end(imprumuturi),
                        [](const Imprumut& a, const Imprumut& b) {
                            return a.getDurata() < b.getDurata();
                        });
}

int numarCartiDeLaAutor(Catalog& catalog, const string& autor) {
    int count = 0;
    for (const auto& carte : catalog.getCarti()) {
        if (carte->getAutor() == autor) {
            ++count;
        }
    }
    return count;
}

int main() {
    vector<Imprumut> imprumuturi;
    Catalog catalog;

    string dataCurenta = "2024-01-10";
    vector<Imprumut> imprumuturiDepasite = extrageImprumuturiDepasite(imprumuturi, dataCurenta);

    string autor = "Mircea Eliade";
    int numarCarti = numarCartiDeLaAutor(catalog, autor);

    Imprumut imprumutMax = imprumutMaxDurata(imprumuturi);

    return 0;
};