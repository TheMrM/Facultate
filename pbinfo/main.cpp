#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a;
    cin >> a;
    int i = 1;
    int j = 16;

    while (j > 0) {
        if (j % 2 == 1) {
            i = i * a;
        }

        a *= a;
        j /= 2;
    }
    cout << i;

    return 0;
}