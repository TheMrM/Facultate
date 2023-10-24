#include <iostream>
#include <cstdlib>
using namespace std;

struct Cont {
    private:
        int NUMARCONT;
        double SOLD = 0.0;
        float RATADOBANZII;

    public:
        void setNumarCont(int numarCont);
        void setSold(double sold);
        void setRataDobanda(float RataDobanda);
        int getNumarCont();
        double getSold();
        float getRataDobanda();
        double calculeazaProcentaj();
        void depunere(double suma);
        void retragere(double suma);
};

void Cont::setNumarCont(int numarCont) {
    NUMARCONT = numarCont;
}

void Cont::setSold(double sold) {
    SOLD = sold;
}

void Cont::setRataDobanda(float RataDobanda) {
    RATADOBANZII = RataDobanda;
}

int Cont::getNumarCont() {
    return NUMARCONT;
}

double Cont::getSold() {
    return SOLD;
}

float Cont::getRataDobanda() {
    return RATADOBANZII;
}

double Cont::calculeazaProcentaj() {
    return SOLD * (RATADOBANZII / 100.0);
}

void Cont::depunere(double suma) {
    SOLD += suma;
}

void Cont::retragere(double suma) {
    if (SOLD >= suma) {
        SOLD -= suma;
    } else {
        cout << "Insufficient funds" << endl;
    }
}

int main() {
    int OptiunePrimara, OptiuneCont, OptiuneNumarCont, OptiuneSold;
    double DobandaSold = 0.0;
    Cont cont; // Create an instance of the Cont struct

    while (OptiunePrimara != 3) {
        cout << "1 - Afisare ContCurent" << endl;
        cout << "2 - Selecteaza alt cont" << endl;
        cout << "3 - Exit" << endl;
        cin >> OptiunePrimara;

        if (OptiunePrimara == 1) {
            int OptiuneCont = 0;

            while (OptiuneCont != 3) {
                cout << "1 - Verificare sold" << endl;
                cout << "2 - Alte optiuni" << endl;
                cout << "3 - Meniu anterior" << endl;
                cin >> OptiuneCont;

                if (OptiuneCont == 1) {
                    cout << "Sold-ul disponibil este " << cont.getSold() << " $" << endl;
                } else if (OptiuneCont == 2) {
                    int OptiuneSold = 0;

                    while (OptiuneSold != 4) {
                        cout << "1 - Depunere numerar" << endl;
                        cout << "2 - Retragere numerar" << endl;
                        cout << "3 - Dobanda" << endl;
                        cout << "4 - Meniu anterior" << endl;
                        cin >> OptiuneSold;

                        if (OptiuneSold == 1) {
                            double suma;
                            cout << "Introduceti suma pe care doriti sa o depuneti: ";
                            cin >> suma;
                            cont.depunere(suma);
                            cout << "Sold-ul disponibil este acum " << cont.getSold() << "$" << endl;
                        } else if (OptiuneSold == 2) {
                            double suma;
                            cout << "Introduceti suma pe care doriti sa o retrageti: ";
                            cin >> suma;
                            cont.retragere(suma);
                            cout << "Sold-ul disponibil este acum " << cont.getSold() << "$" << endl;
                        } else if (OptiuneSold == 3) {
                            cout << "Ce dobanda doriti din Soldul curent (" << cont.getSold() << "$): ";
                            cin >> DobandaSold;
                            double dobanda = (DobandaSold / 100.0) * cont.getSold();
                            double newBalance = cont.getSold() + dobanda;
                            cout << "Dobanda procentuala de " << DobandaSold << " % din soldul curent " << cont.getSold() << "$ este " << dobanda << " $"<< endl;
                            cout << "Sold-ul disponibil este acum " << newBalance << " $" << endl;
                            cont.setSold(newBalance);
                        }
                    }
                }
            }
        } 
        else if (OptiunePrimara == 2) {
            Cont newAccount;

            cout << "Introduceti o suma initiala pentru noul cont: " << endl;
            double initialBalance;
            cin >> initialBalance;

            newAccount.setSold(initialBalance);

            int OptiuneCont = 0;

            while (OptiuneCont != 3) {
                cout << "1 - Verificare sold" << endl;
                cout << "2 - Alte optiuni" << endl;
                cout << "3 - Meniu anterior" << endl;
                cin >> OptiuneCont;

                if (OptiuneCont == 1) {
                    cout << "Sold-ul disponibil este " << cont.getSold() << " $" << endl;
                } else if (OptiuneCont == 2) {
                    int OptiuneSold = 0;

                    while (OptiuneSold != 4) {
                        cout << "1 - Depunere numerar" << endl;
                        cout << "2 - Retragere numerar" << endl;
                        cout << "3 - Dobanda" << endl;
                        cout << "4 - Meniu anterior" << endl;
                        cin >> OptiuneSold;

                        if (OptiuneSold == 1) {
                            double suma;
                            cout << "Introduceti suma pe care doriti sa o depuneti: ";
                            cin >> suma;
                            cont.depunere(suma);
                            cout << "Sold-ul disponibil este acum " << cont.getSold() << "$" << endl;
                        } else if (OptiuneSold == 2) {
                            double suma;
                            cout << "Introduceti suma pe care doriti sa o retrageti: ";
                            cin >> suma;
                            cont.retragere(suma);
                            cout << "Sold-ul disponibil este acum " << cont.getSold() << "$" << endl;
                        } else if (OptiuneSold == 3) {
                            cout << "Ce dobanda doriti din Soldul curent (" << cont.getSold() << "$): ";
                            cin >> DobandaSold;
                            double dobanda = (DobandaSold / 100.0) * cont.getSold();
                            double newBalance = cont.getSold() + dobanda;
                            cout << "Dobanda procentuala de " << DobandaSold << " % din soldul curent " << cont.getSold() << "$ este " << dobanda << " $"<< endl;
                            cout << "Sold-ul disponibil este acum " << newBalance << " $" << endl;
                            cont.setSold(newBalance);
                        }
                    }
                }
            }
        }
    }

    if (OptiunePrimara == 3) {
        cout << "O zi buna!" << endl;
        exit(0);
    }

    return 0;
}
