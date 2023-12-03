#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <limits>

using namespace std;
using namespace chrono;

class produs {
    int cod;
    string nume;
    double pret;
    string unitateMasura;
    int cantitate;
    double reducere;

public:
    produs(int cod, string nume, double pret, string unitateMasura, int cantitate, double reducere) 
    : cod(cod), nume(nume), pret(pret), unitateMasura(unitateMasura), cantitate(cantitate), reducere(reducere) {}

    double calculatePrice() const {
        return (pret * cantitate) * (1 - reducere / 100);
    }

    int getCod() const { return cod; }
    string getNume() const { return nume; }
    double getPret() const { return pret; }
    int getCantitate() const { return cantitate; }
    double getReducere() const { return reducere; }
    string getUnitateMasura() const { return unitateMasura; }
};

class factura {
    static int contorFactura;
    string numarFactura;
    string dataEmitere;
    string oraEmitere;
    double pretInitial;
    double TVA;
    double reducereFactura;
    double pretTotal;
    vector<produs> produse;

public:
    factura(double TVA, double reducereFactura)
    : pretInitial(0), TVA(TVA), reducereFactura(reducereFactura), pretTotal(0) {
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

    void addProdus(const produs& p) {
    produse.push_back(p);
    pretInitial += p.calculatePrice();
    }

    double calculateTotal() {
        double subtotal = pretInitial * (1 - reducereFactura / 100);
        return subtotal * (1 + TVA / 100);
    }

    string afiseazaProduse() const {
    ostringstream stream;
    stream << left << setw(10) << "Cod" << setw(20) << "Nume Produs" << setw(15) << "Unitate"
           << setw(10) << "Cantitate" << setw(10) << "Pret" << setw(10) << "Discount" << setw(15) << "Pret Final" << "\n";
    stream << string(90, '-') << "\n";
    for (const auto& prod : produse) {
        double priceBeforeDiscount = prod.getPret() * prod.getCantitate();
        double discountedPrice = priceBeforeDiscount * (1 - prod.getReducere() / 100);
        stream << left << setw(10) << prod.getCod() << setw(20) << prod.getNume() << setw(15) << prod.getUnitateMasura()
               << setw(10) << prod.getCantitate() << setw(10) << fixed << setprecision(2) << prod.getPret()
               << setw(10) << prod.getReducere() << setw(15) << discountedPrice << "\n";
    }
    return stream.str();
}

    string afiseazaFactura() {
    pretTotal = calculateTotal();
    double pretDupaReducere = pretInitial * (1 - reducereFactura / 100);
    double tvaAmount = pretDupaReducere * TVA / 100;

    ostringstream stream;
    stream << fixed << setprecision(2);
    stream << "----------------------------------- Factura Nr. " << numarFactura << " -----------------------------------\n";
    stream << "Data emiterii: " << dataEmitere << "   Ora: " << oraEmitere << "\n\n";
    stream << "Detalii Produse:\n" << afiseazaProduse();
    stream << "\n---------------------------------------------------------------------------------------------\n";
    stream << setw(30) << left << "Pret initial total:" << setw(20) << right << pretInitial << " RON\n"
           << setw(30) << left << "Reducere factura:" << setw(20) << right << reducereFactura << "%\n"
           << setw(30) << left << "Pret dupa reducere:" << setw(20) << right << pretDupaReducere << " RON\n"
           << setw(30) << left << "TVA (" << TVA << "%):" << setw(20) << right << tvaAmount << " RON\n"
           << "\n---------------------------------------------------------------------------------------------\n"
           << setw(30) << left << "Pret total cu TVA:" << setw(20) << right << pretTotal << " RON\n"
           << "---------------------------------------------------------------------------------------------\n";
    return stream.str();
    }
};

int factura::contorFactura = 0;

double getValidatedDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valoare invalida. Incercati din nou.\n";
    }
    return value;
}

int main() {
    const double TVA = 19.0;
    char createInvoice = 'y';

    while (createInvoice == 'y' || createInvoice == 'Y') {
        double reducereFactura = getValidatedDouble("Introduceti discount la factura (procent): ");
        factura n1(TVA, reducereFactura);

        char addMore = 'y';
        do {
            int cod = (int)getValidatedDouble("Introduceti cod produs: ");
            string nume, unitateMasura;
            cout << "Introduceti nume produs: ";
            cin >> nume;
            double pret = getValidatedDouble("Introduceti pret produs/unitate: ");
            cout << "Introduceti unitate de masura: ";
            cin >> unitateMasura;
            int cantitate = (int)getValidatedDouble("Introduceti cantitate: ");
            double reducere = getValidatedDouble("Introduceti discount produs (procent): ");

            produs newProdus(cod, nume, pret, unitateMasura, cantitate, reducere);
            n1.addProdus(newProdus);

            cout << "Doriti sa adaugati mai multe produse? (y/n): ";
            cin >> addMore;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        } while (addMore == 'y' || addMore == 'Y');

        cout << n1.afiseazaFactura() << endl;

        cout << "Doriti sa creati o factura noua? (y/n): ";
        cin >> createInvoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }

    return 0;
}
