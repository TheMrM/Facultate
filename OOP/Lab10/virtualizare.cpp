#include <iostream>

using namespace std;

class formaGeometrica {
public:
    virtual float aria() const = 0;
    virtual ~formaGeometrica() {}
};

class patrat : public formaGeometrica {
private:
    float latura;
public:
    patrat(float l) : latura(l) {}
    float aria() const override {
        return latura * latura;
    }
};

class cerc : public formaGeometrica {
private:
    float raza;
public:
    cerc(float r) : raza(r) {}
    float aria() const override {
        return 3.14 * raza * raza;
    }
};

int main() {
    formaGeometrica* forma1 = new patrat(5);
    formaGeometrica* forma2 = new cerc(3);

    cout << "Aria patratului este: " << forma1->aria() << endl;
    cout << "Aria cercului este: " << forma2->aria() << endl;

    delete forma1;
    delete forma2;

    return 0;
}
