#include <iostream>

using namespace std;

class Marfa {
    static int CodGestiune;

public:
    static int SchimbaGestiune() {
        return ++CodGestiune;
    }
};

int Marfa::CodGestiune = 0;

int main() {
    int cod;
    cod = Marfa::SchimbaGestiune();

    cout << "Codul de gestiune este " << cod <<endl;

    return 0;
}