#include <stdio.h>

#define PI 3.14159

int main() {
    long long r, A, V;
    long long a, v;

    // Citim raza sferei
    if (scanf("%lld", &r) != 1) {
        return -1;
    }

    // Calculam aria si volumul sferei
    A = 4 * PI * r * r;
    V = 4 * PI * r * r * r / 3;

    // Multiplicam cu 100 pentru a converti in long long ca sa trunchiem partea zecimala
    a = (long long)(A * 100);
    v = (long long)(V * 100);

    // Afisam aria si volumul
    printf("%lld.%lld%lld ", a / 100, (a / 10) % 10, a % 10);
    printf("%lld.%lld%lld\n", v / 100, (v / 10) % 10, v % 10);

    return 0;
}
