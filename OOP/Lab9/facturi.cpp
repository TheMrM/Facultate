#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <sstream>

using namespace std;
using namespace chrono;

class produs {
    int cod;
    string nume;
    double pret;
    string unitateMasura;
    int cantitate;
    int reducere;

public:
    produs(int cod, string nume, double pret, string unitateMasura, int cantitate, int reducere) 
    : cod(cod), nume(nume), pret(pret), unitateMasura(unitateMasura), cantitate(cantitate), reducere(reducere) {}

    double getPret() const { return pret; }
    int getCantitate() const { return cantitate; }
};

class factura {
    static int contorFactura;

    string numarFactura;
    string dataEmitere;
    string oraEmitere;
    double pretInitial;
    double TVA;
    double pretTVA;
    double reducere;
    double pretCuReducere;
    double pretTotal;
    vector<produs> produse;

public:
    factura(double TVA, double reducere) : TVA(TVA), reducere(reducere), pretInitial(0), pretTVA(0), pretCuReducere(0), pretTotal(0){

    contorFactura++;
    numarFactura = to_string(contorFactura);

    auto now = system_clock::now();
    time_t now_c = system_clock::to_time_t(now);
    tm now_tm = *localtime(&now_c);

    stringstream date_stream, time_stream;
    date_stream << put_time(&now_tm, "%d-%m-%Y");
    time_stream << put_time(&now_tm, "%H:%M:%S");

    dataEmitere = date_stream.str();
    oraEmitere = time_stream.str();
    }

    void addProdus(const produs& prod) {
        produse.push_back(prod);
        pretInitial += prod.getPret() * prod.getCantitate();
        double discount = pretInitial * (reducere / 100.0);
        pretCuReducere = pretInitial - discount;
        pretTVA = pretCuReducere * (1 + TVA / 100.0);
        pretTotal = pretTVA;
        
    }

    string afiseazaFactura() const {
        ostringstream stream;
        stream << fixed << setprecision(2);
        stream << "Numar factura: " << contorFactura << "\nData emiterii: " << dataEmitere << "\nOra emitere: " << oraEmitere << "\nPret initial: " << pretInitial << " RON" << "\nReducere: " << reducere << " RON" << "\nPret cu reducere: " << pretCuReducere << " RON"<< "\nTVA: "<< TVA << " %"<< "\nPret cu TVA: " << pretTVA << " RON"<< "\nPret total: " << pretTotal << " RON";

        return stream.str();
    }
};

int factura::contorFactura = 0;

int main() {
    produs franzela(1, "franzela", 9.45, "buc", 5, 10);
    factura n1(19, 5);

    n1.addProdus(franzela);

    cout << n1.afiseazaFactura() << endl;

    return 0;
}
