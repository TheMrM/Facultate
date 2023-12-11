#include <iostream>
#include <string>

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

    void afisare() const {
        cout << "Autor " << autor << " , An " << an << endl;
    }
};

class Pictura : public Tablou {
private:
    string stilPictura;

public:
    Pictura(const string& autor, int an, const string& stilPictura) : Tablou(autor, an), stilPictura(stilPictura) {}
    
    void stil() const override {
        cout << "Tabloul are un stil abstract " << endl;
    }
};

class Fotografie {};

class Colaj {};

int main() {

}