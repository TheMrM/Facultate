#include <stdio.h>

int main() {
    unsigned long long n;
    int Z = 0, U = 0;

    if (scanf("%llu", &n) != 1) return 1;

    while (n > 0) {
        if (n % 2 == 0) Z++;
        else U++;
        n /= 2;
    }
    printf("%d %d\n", Z, U);

    return 0;
}
