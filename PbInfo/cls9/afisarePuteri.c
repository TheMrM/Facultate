#include <stdio.h>

int main() {
    int n, p;
    long long putere = 1;

    if (scanf("%d %d", &n, &p) != 2) return 1;

    while (putere <= p) {
        printf("%lld ", putere);
        if (putere > p / n) break;
        putere *= n;
    }

return 0;
}
