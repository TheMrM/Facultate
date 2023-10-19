#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;

// Function for addition
void Add(const int* a, int size_a, const int* b, int size_b, int* s, int& size_s) {
    int carry = 0;
    int max_size = std::max(size_a, size_b);
    size_s = max_size + 1; // Ensure enough space for carry

    for (int i = 0; i < max_size; i++) {
        int sum = carry;
        if (i < size_a) {
            sum += a[i];
        }
        if (i < size_b) {
            sum += b[i];
        }

        s[i] = sum % 256;
        carry = sum / 256;
    }

    s[max_size] = carry;
    if (s[max_size] == 0) {
        size_s--;
    }
}

// Function for subtraction
void Sub(const int* a, int size_a, const int* b, int size_b, int* s, int& size_s) {
    int borrow = 0;
    int max_size = std::max(size_a, size_b);
    size_s = max_size;

    for (int i = 0; i < max_size; i++) {
        int diff = -borrow;
        if (i < size_a) {
            diff += a[i];
        }
        if (i < size_b) {
            diff -= b[i];
        }

        if (diff < 0) {
            diff += 256;
            borrow = 1;
        } else {
            borrow = 0;
        }

        s[i] = diff;
    }

    while (size_s > 0 && s[size_s - 1] == 0) {
        size_s--;
    }
}

// Function for multiplication
void Mul(const int* a, int size_a, const int* b, int size_b, int* s, int& size_s) {
    size_s = size_a + size_b;
    std::memset(s, 0, size_s * sizeof(int));

    for (int i = 0; i < size_a; i++) {
        int carry = 0;
        for (int j = 0; j < size_b; j++) {
            int product = s[i + j] + a[i] * b[j] + carry;
            s[i + j] = product % 256;
            carry = product / 256;
        }
        s[i + size_b] += carry;
    }

    while (size_s > 0 && s[size_s - 1] == 0) {
        size_s--;
    }
}

int main() {
    int a[MAX_SIZE], b[MAX_SIZE], result[MAX_SIZE];
    int size_a, size_b, size_result;

    // Citirea dimensiunii primului număr de la utilizator
    std::cout << "Introduceti dimensiunea primului numar: ";
    std::cin >> size_a;

    // Citirea elementelor primului număr de la utilizator
    std::cout << "Introduceti elementele primului numar: ";
    for (int i = 0; i < size_a; i++) {
        std::cin >> a[i];
    }

    // Citirea dimensiunii celui de-al doilea număr de la utilizator
    std::cout << "Introduceti dimensiunea celui de-al doilea numar: ";
    std::cin >> size_b;

    // Citirea elementelor celui de-al doilea număr de la utilizator
    std::cout << "Introduceti elementele celui de-al doilea numar: ";
    for (int i = 0; i < size_b; i++) {
        std::cin >> b[i];
    }

    // Apelarea funcției de adunare
    Add(a, size_a, b, size_b, result, size_result);

    // Afișarea rezultatului adunării
    std::cout << "Rezultatul adunarii: ";
    for (int i = 0; i < size_result; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // Apelarea funcției de scădere
    Sub(a, size_a, b, size_b, result, size_result);

    // Afișarea rezultatului scăderii
    std::cout << "Rezultatul scaderii: ";
    for (int i = 0; i < size_result; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // Apelarea funcției de înmulțire
    Mul(a, size_a, b, size_b, result, size_result);

    // Afișarea rezultatului înmulțirii
    std::cout << "Rezultatul inmultirii: ";
    for (int i = 0; i < size_result; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
