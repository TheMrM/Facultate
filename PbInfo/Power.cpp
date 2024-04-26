#include <iostream>

using namespace std;
int main() {

    int a, b;
    std::cin >> a >> b;

    if (b == 0) {
        cout << 1;
        return 0;
    }

    long long P = 1;
    for (int i = 0; i < b; i++) {
        P *= a;
        if (P > 2000000000) return 0;
    }

    cout << P;

    return 0;
}
