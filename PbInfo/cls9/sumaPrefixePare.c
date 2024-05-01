#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long S = 0;
    long long factor = 1;

    // Find the largest power of 10 that is smaller than n
    while (factor * 10 <= n) {
        factor *= 10;
    }

    // Extract and sum every prefixes
    while (factor > 0) {
        long long prefix = n / factor;
        if (prefix % 2 == 0) {
            S += prefix;
        }
        factor /= 10;
    }

    printf("%lld\n", S);
    return 0;
}
