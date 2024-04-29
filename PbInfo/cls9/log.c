#include <stdio.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 1;

    int exponent = 0;
    int current_prod = 1;

    while (current_prod != m) {
        current_prod *= n;
        exponent++;
    }

    printf("%d\n", exponent);

    return 0;
}
