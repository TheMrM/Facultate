#include <iostream>

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
    std::cout << "Introduceti valoarea lui k: ";
    std::cin >> k;

    int result = ElementK(k);
    std::cout << "Al " << k << "-lea element este: " << result << std::endl;

    return 0;
}
