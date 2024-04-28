#include <stdio.h>
#include <math.h>

int main() {
    
    int r;
    double A, V;
    if (scanf("%d", &r) != 1) {
        return 1;
    }

    A = 4 * M_PI * r * r;
    V = (4.0/3) * M_PI * r * r * r;

    A = floor(A * 100) / 100;
    V = floor(V * 100) / 100;

    printf("%.2f %.2f\n", A, V);
    return 0;
}
