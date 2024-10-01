#include <iostream>

using namespace std;

int ElementK(int k) {
    int x = 0;
    int sum = 0;

    while (sum < k) {
        x++;
        sum += x;
    }

    return x;
}

int main() {
    int k;
    cout << "Introduceti valoarea lui k: ";
    cin >> k;

    int result = ElementK(k);
    cout << "Al " << k << "-lea element este: " << result << endl;

    return 0;
}
