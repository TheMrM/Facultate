#include <stdio.h>

int countOne(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned long long n, m;
    int onesA, onesB;
    if (scanf("%llu %llu", &n, &m) != 2) return 1;

    onesA = countOne(n);
    onesB = countOne(m);

    if (onesA > onesB) {
        printf("%llu\n", n);
    } else if (onesB > onesA) {
        printf("%llu\n", m);
    } else {
        if (n < m) {
            printf("%llu\n", n);
        } else {
            printf("%llu\n", m);
        }
    }

    return 0;
}
