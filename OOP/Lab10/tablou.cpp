#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tablou {
private:
    string autor;
    int an;

public:
    Tablou() : autor(""), an(0) {}
    Tablou(const string& autor, int an) : autor(autor), an(an) {}

    virtual void stil() const {
        cout << "Stilul tabloului nu este definit." << endl;
    }

    virtual void afisare() const {
        cout << "Autor " << autor << " , An " << an << endl;
    }
};

class Pictura : virtual public Tablou {
private:
    string stilPictura;

public:
    Pictura(const string& autor, int an, const string& stilPictura) : Tablou(autor, an), stilPictura(stilPictura) {}

    void stil() const override {
        cout << "Tabloul are un stil abstract " << endl;
    }

    void afisare() const override {
        Tablou::afisare();
        cout << "Stil: " << stilPictura << endl;
    }
};

class Fotografie : virtual public Tablou {
private:
    string locatie;

public:
    Fotografie(const string& autor, int an, const string& locatie) : Tablou(autor, an), locatie(locatie) {}

    void afisare() const override {
        Tablou::afisare();
        cout << "Locatie: " << locatie << endl;
    }
};

class Colaj : public Fotografie, public Pictura {
public:
    Colaj(const string& autor, int an, const string& locatie, const string& stilPictura)
        : Tablou(autor, an), Fotografie(autor, an, locatie), Pictura(autor, an, stilPictura) {}

    void afisare() const override {
        Fotografie::afisare();
        Pictura::afisare();
    }
};

int main() {
    vector<Tablou*> expozitie;

    expozitie.push_back(new Pictura("Picasso", 1950, "Cubism"));
    expozitie.push_back(new Pictura("Van Gogh", 1889, "Post-Impressionism"));

    expozitie.push_back(new Fotografie("Ansel Adams", 1940, "Yosemite"));
    expozitie.push_back(new Fotografie("Dorothea Lange", 1936, "Great Depression"));

    expozitie.push_back(new Colaj("Artist", 2000, "Cityscape", "Modern"));

    for (const auto& tablou : expozitie) {
        tablou->afisare();
        cout << "---------------------" << endl;
    }

    for (const auto& tablou : expozitie) {
        delete tablou;
    }

    return 0;
}