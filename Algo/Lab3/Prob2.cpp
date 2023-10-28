#include <iostream>
#include <vector>

using namespace std;

int calculateBinomialCoefficient(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }

    vector<int> coefficients(k + 1, 0);
    coefficients[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            coefficients[j] = coefficients[j] + coefficients[j - 1];
        }
    }

    return coefficients[k];
}

int main() {
    int n, k;
    cout << "Introduceti n: ";
    cin >> n;
    cout << "Introduceti k: ";
    cin >> k;

    int result = calculateBinomialCoefficient(n, k);
    cout << "C(" << n << ", " << k << ") = " << result << endl;

    return 0;
}
