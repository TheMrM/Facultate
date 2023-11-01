#include <iostream>
#include <string>

using namespace std;

class ProdusAlimentar {
    static int CotaTVA;
    static int CodGestiune;
    const int Cod;
    string denumire;
    double pret;
    int cantitate;
    double valoare;

public:
    ProdusAlimentar(const string& nume, double p, int c)
        : Cod(CodGestiune), denumire(nume), pret(p), cantitate(c) {
        double valoareFaraTVA = pret * cantitate;
        valoare = valoareFaraTVA + valoareFaraTVA * CotaTVA / 100;
        }

    static int getSchimbaGestiune() {
        return ++CodGestiune;
    }

    string getDenumire() {
        return denumire;
    }

    double getPret() {
        return pret;
    }

    int getCantitate() {
        return cantitate;
    }

    int getValoare() {
        return valoare;
    }
};

int ProdusAlimentar::CodGestiune = 1; 
int ProdusAlimentar::CotaTVA = 19;

int main() {
    string denumire;
    double pret;
    int cantitate;

    cout << "Introduceti denumirea: ";
    cin >> denumire;

    cout << "Introduceti pretul: ";
    cin >> pret;

    cout << "Introduceti cantitatea: ";
    cin >> cantitate;

    ProdusAlimentar produs(denumire, pret, cantitate);
    int cod = ProdusAlimentar::getSchimbaGestiune();

    cout << "Codul de gestiune este " << cod << endl;
    cout << "Denumire produs: " << produs.getDenumire() << endl;
    cout << "Pret: " << produs.getPret() << endl;
    cout << "Cantitate: " << produs.getCantitate() << endl;
    cout << "Valoare: " << produs.getValoare() << endl;

    return 0;
}