#include <stdio.h>
#include <math.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        long long x;
        if (scanf("%lld", &x) != 1) return 1;

        long long root = (long long) sqrt(x);

        if (root * root == x) {
            printf("DA\n");
        } else {
            printf("NU\n");
        }
    }

    return 0;
}
