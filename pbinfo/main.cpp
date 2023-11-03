#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double l;
    cin >> n >> l;

    const double pi = 3.14159265358979323846;

    double halfAngel = pi / n;
    double tanHalfAngel = tan(halfAngel);

    double A = n * l * l / (4 * tanHalfAngel * tanHalfAngel);
    cout << fixed << setprecision(2) << A << endl;

    return 0;
}
