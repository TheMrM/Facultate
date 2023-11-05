#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    double cot = 1.0 / tan(M_PI /n);
    float A = static_cast<double>(n * l * l * cot) /4.0;
    A = (int)(A * 100.0) / 100.0;
    
    cout << A;

    return 0;
}