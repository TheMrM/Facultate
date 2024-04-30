#include <stdio.h>

int main() {
    int n, S = 0; 
    if (scanf("%d", &n) != 1) return 1;
    
    if (n < 0) return 1;

    for(int i = 1; i <= n; i++) {
        S += i * (i + 1);
    }

    printf("Rezultatul este %d", S);
    return 0;
}
