#include <iostream>
#include <iomanip>
#include "triunghi.h"

using namespace std;

Triunghi::Triunghi() : lungime(0), latime(0) {}

Triunghi::Triunghi(double lung, double lat) {
    setDimensiune(lung, lat);
}

void Triunghi::setDimensiune(double lung, double lat) {
    lungime = (lung >= 0) ? lung : 0;
    latime = (lat >= 0) ? lat : 0;
}

double Triunghi::getLungime() const {
    return lungime;
}

double Triunghi::getLatime() const {
    return latime;
}

double Triunghi::arie() const {
    return lungime * latime;
}

double Triunghi::perimetru() const {
    return 2 * (lungime + latime);
}

void Triunghi::print() const {
    cout << fixed << showpoint << setprecision(2);
    const int lat = 10;

    cout << "Lungime: " << setw(lat) << lungime << endl;
    cout << "Latime: " << setw(lat) << latime << endl;
    cout << "Arie: " << arie() << endl;
    cout << "Perimetru: " << perimetru() << endl;
}
