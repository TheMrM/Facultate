#include <iostream>
#include <string>

class ProdusAlimentar {
    static int CotaTVA;
    static int CodGestiune;
    const int Cod;
    std::string denumire;
    double pret;
    int cantitate;
    double valoare;

public:
    ProdusAlimentar(const std::string& nume, double p, int c)
        : Cod(CodGestiune), denumire(nume), pret(p), cantitate(c) {
        double valoareFaraTVA = pret * cantitate;
        valoare = valoareFaraTVA + valoareFaraTVA * CotaTVA / 100;
        }

    static int getSchimbaGestiune() {
        return ++CodGestiune;
    }

    std::string getDenumire() {
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
    std::string denumire;
    double pret;
    int cantitate;

    std::cout << "Introduceti denumirea: ";
    std::cin >> denumire;

    std::cout << "Introduceti pretul: ";
    std::cin >> pret;

    std::cout << "Introduceti cantitatea: ";
    std::cin >> cantitate;

    ProdusAlimentar produs(denumire, pret, cantitate);
    int cod = ProdusAlimentar::getSchimbaGestiune();

    std::cout << "Codul de gestiune este " << cod << std::endl;
    std::cout << "Denumire produs: " << produs.getDenumire() << std::endl;
    std::cout << "Pret: " << produs.getPret() << std::endl;
    std::cout << "Cantitate: " << produs.getCantitate() << std::endl;
    std::cout << "Valoare: " << produs.getValoare() << std::endl;

    return 0;
}