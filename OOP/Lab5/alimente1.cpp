#include <iostream>
#include <string>
using namespace std;
class ProdusAlimentar{
    const int cod;
    int pret;
    int cantitate;
    int valoare;
    string denumire;
    static int cotaTVA;
public:
    ProdusAlimentar():cod(0)
    {}
    ProdusAlimentar(string,int,int,int);
    void afis()
    {   
        cout<<denumire;
        cout<<"\n produsul :"<< denumire << " " <<cod<<" "<<pret<<" "<<cantitate<<" "<<cotaTVA<<" cu valoare calculata" <<valoare;
    }
    static void ModificaTVA(int nouacotaTVA)
    {
        cotaTVA=nouacotaTVA;
    }
};


 int ProdusAlimentar::cotaTVA=19;

ProdusAlimentar::ProdusAlimentar(string d, int a, int b, int c):cod(a)
{
    denumire=d;
    pret=b;
    cantitate=c;
    valoare=pret*cantitate;
}

int main()
{
    ProdusAlimentar baneasa;
    ProdusAlimentar margarina("Rama",12,13,1000);
    ProdusAlimentar  ciocolata("Milka",123,20, 300);
baneasa.afis();
margarina.afis();
ciocolata.afis();

ProdusAlimentar::ModificaTVA(24);

baneasa.afis();
margarina.afis();
ciocolata.afis();

}