#include <stdio.h>

int main() {
    long long n, f1 = 1, f2 = 1, fn;
    if (scanf("%lld", &n) != 1) return 1;

    if ( n < 1) return 1;

    if (n >= 1) printf("%lld %lld ", f1, f2);

    while ((fn = f1 + f2) <= n) {
        printf("%lld ", fn);
        f1 = f2;
        f2 = fn;
    }
    return 0;
}
