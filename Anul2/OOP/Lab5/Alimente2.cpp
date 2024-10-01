#include <iostream>
#include <string>

using namespace std;

class ProdusAlimentar {
    const int cod;
    int pret;
    int cantitate;
    string denumire;
    static int cotaTVA;

public:
    ProdusAlimentar(int c, string d, int p, int q) : cod(c), denumire(d), pret(p), cantitate(q) {}

    int calculValoareProdus() {
        return pret * cantitate + pret * cantitate * cotaTVA / 100;
    }

    void afisareProdus() {
        cout << "Cod: " << "#" << cod << endl;
        cout << "Denumire: " << denumire << endl;
        cout << "Pret unitar: " << pret << " Ron"<< endl;
        cout << "Cantitate: " << cantitate << " bucati" <<endl;
        cout << "Valoare cu TVA: " << calculValoareProdus() << " Ron" << endl;
        cout << "Cota TVA: " << cotaTVA << "%" << endl;
    }

    static void modificareCotaTVA(int nouaCotaTVA) {
        cotaTVA = nouaCotaTVA;
    }
};

int ProdusAlimentar::cotaTVA = 19;

int main() {
    ProdusAlimentar produs1(1, "Capsuni", 5, 10);
    ProdusAlimentar produs2(2, "Banane", 8, 10);
    ProdusAlimentar produs3(3, "Mere", 4, 5);

    cout << "Produse inainte de modificarea cotei TVA:\n";
    produs1.afisareProdus();
    produs2.afisareProdus();
    produs3.afisareProdus();

    ProdusAlimentar::modificareCotaTVA(24);

    cout << "\nProdus dupa modificarea cotei TVA:\n";
    produs1.afisareProdus();
    produs2.afisareProdus();
    produs3.afisareProdus();

    return 0;
}