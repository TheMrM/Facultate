#include <stdio.h>

int main() {
    int n, MIN, numar;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 1 || n > 1000) return 1;

    if (scanf("%d", &MIN) != 1) return 1;

    for (int i = 1; i < n; i++) {
        if (scanf("%d", &numar) != 1) return 1;
        if (numar < MIN) MIN = numar;
    }
    
    printf("%d", MIN);

    return 0;
}
