#include <stdio.h>

int main() {
    long long n, S = 0;

    if (scanf("%lld", &n) != 1) return 1;

    while (n != 0) {
        S += n;
        n /= 10;
    }

    printf("%lld\n", S);
}
