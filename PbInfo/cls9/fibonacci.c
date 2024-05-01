#include <stdio.h>

int main() {
    int n, f1 = 1, f2 = 1, fn;

    if (scanf("%d", &n) != 1) return 1;

    if (n < 1) return 1;

    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == 2) {
            printf("%d ", 1);
        } else {
            fn = f1 + f2;
            printf("%d ", fn);
            f1 = f2;
            f2 = fn;
        }
    }
    return 0;
}
