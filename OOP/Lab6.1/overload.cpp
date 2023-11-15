#include <iostream>
#include <cstring>

using namespace std;

class sir{
    int lung;
    char *psir;

    public:
        sir(const char *s);
        sir(int l=100);
        sir(const sir&s);
        void modifica();
        void afisare();
        sir& operator = (const sir& s);
        sir operator + (const sir &s);
        ~sir();
};

sir::sir(const char *s) {
    lung = strlen(s);
    psir = new char[lung + 1];
    strcpy(psir, s);
};

sir::sir(int l) {
    lung = l;
    psir = new char[lung + 1];
    *psir='\0';
};

sir::sir(const sir& s) {
    lung = s.lung;
    psir = new char[lung + 1];
    strcpy(psir, s.psir);
};

void sir::modifica() {
    strcpy(psir, "bau");
};

sir sir::operator+(const sir &s) {
    sir aux;
    aux.lung = lung + s.lung;
    aux.psir = new char[aux.lung + 1];
    strcpy(aux.psir, psir);
    strcat(aux.psir, s.psir);
    return aux;
};

sir::~sir() {
    delete []psir;
};

sir& sir::operator = (const sir& s) {
    if (this!=&s) {
        delete this->psir;
        this->lung=s.lung;
        this->psir=new char[lung + 1];
        strcpy(psir, s.psir);
        return *this;
    }
    return *this;
};

void sir::afisare() {
    cout << psir;
};

int main() {
    sir s1="cucu";
    sir s2=s1;
    s1.modifica();
    sir s3="baba";
    sir s4;
    s4 = s3;
    s3.modifica();
    s4 = s1 + s2;
    s4.afisare();

    return 0;
}