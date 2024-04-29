#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 1;

    long long low = 1, high = 30000000, mid;
    long long sum, m = -1;

    while (low <= high) {
        mid = (low + high) / 2;
        sum = mid * (mid + 1) / 2;

        if (sum >= n) { m = mid; high = mid-1; }
        else { low = mid + 1; }
    }

    printf("%lld\n", m);
    return 0;
}
