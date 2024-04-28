#include <stdio.h>
#include <math.h>

int main() {

    double a, b, c;

    if (scanf("%lf", &a) != 1 || scanf("%lf", &b) != 1 || scanf("%lf", &c) != 1) return 1;

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Imposibil\n");
        return 0;
    }



    double s = (a + b + c) / 2.0;
    
    double aria = sqrt(s * (s - a) * (s - b) * (s - c));

    if ( aria == 0 ) {
        printf("Imposibil\n");
        return 0;
    }

    double h_a = (2 * aria) / a;
    double h_b = (2 * aria) / b;
    double h_c = (2 * aria) / c;

    printf("%.2f %.2f %.2f\n", h_a, h_b, h_c);

    return 0;
}
