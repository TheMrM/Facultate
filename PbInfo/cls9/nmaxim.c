#include <stdio.h>

int main() {
    int n, numar, MAX;

    if (scanf("%d", &n) != 1) return 1;
    if (n < 1 || n > 1000) return 1;

    if (scanf("%d", &MAX) != 1) return 1;

    for (int i = 1; i < n; i++) {
        if (scanf("%d", &numar) != 1) return 1;
        if (numar > MAX) {
            MAX = numar;
        }
    }

    printf("%d\n", MAX);
    return 0;
}
