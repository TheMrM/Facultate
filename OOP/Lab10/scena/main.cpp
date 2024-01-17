#include <iostream>
#include "triunghi.h"

using namespace std;

int main() {
    double lungime = 10;
    double latime = 6.4;

    Triunghi triunghi(lungime, latime);

    cout << "Triunghi\n";
    triunghi.print();
    cout << endl;

    return 0;
}
