#include <stdio.h>

int main() {
    long long n, i, S = 0;

    if (scanf("%lld", &n) != 1) return 1;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 != 0) {
                S += i;
            }
            if (i != n / i && (n / i) % 2 != 0) {
                S += n / i;
        }
    }
}

    printf("%lld\n", S);
    return 0;
}
