#include <stdio.h>

int main() {
    long long n, S = 0;
    if (scanf("%lld", &n) != 1) return 1;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            S += i;
            if (i != n / i) S += n / i;
        }
    }

    printf("%lld\n", S);

    return 0;
}
