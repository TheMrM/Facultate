#include <iostream>

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

    std::cout << "Codul de gestiune este " << cod <<std::endl;

    return 0;
}