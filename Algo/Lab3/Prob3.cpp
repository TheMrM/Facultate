#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;

void Add(const int* a, int size_a, const int* b, int size_b, int* s, int& size_s) {
    int carry = 0;
    int max_size = max(size_a, size_b);
    size_s = max_size + 1; 

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

void Sub(const int* a, int size_a, const int* b, int size_b, int* s, int& size_s) {
    int borrow = 0;
    int max_size = max(size_a, size_b);
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

void Mul(const int* a, int size_a, const int* b, int size_b, int* s, int& size_s) {
    size_s = size_a + size_b;
    memset(s, 0, size_s * sizeof(int));

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

    cout << "Introduceti dimensiunea primului numar: ";
    cin >> size_a;

    cout << "Introduceti elementele primului numar: ";
    for (int i = 0; i < size_a; i++) {
        cin >> a[i];
    }

    cout << "Introduceti dimensiunea celui de-al doilea numar: ";
    cin >> size_b;

    cout << "Introduceti elementele celui de-al doilea numar: ";
    for (int i = 0; i < size_b; i++) {
        cin >> b[i];
    }

    Add(a, size_a, b, size_b, result, size_result);

    cout << "Rezultatul adunarii: ";
    for (int i = 0; i < size_result; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    Sub(a, size_a, b, size_b, result, size_result);

    cout << "Rezultatul scaderii: ";
    for (int i = 0; i < size_result; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    Mul(a, size_a, b, size_b, result, size_result);

    cout << "Rezultatul inmultirii: ";
    for (int i = 0; i < size_result; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
