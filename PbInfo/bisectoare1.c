#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    if (scanf("%lf", &a) != 1 || scanf("%lf", &b) != 1 || scanf("%lf", &c) != 1) return 1;

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Imposibil");
        return 0;
    }

    double l_a = sqrt((b * c * (1 - ((a * a) / ((b + c) * (b + c))))));
    double l_b = sqrt((a * c * (1 - ((b * b) / ((a + c) * (a + c))))));
    double l_c = sqrt((a * b * (1 - ((c * c) / ((a + b) * (a + b))))));

    l_a = round(l_a * 100) / 100;
    l_b = round(l_b * 100) / 100;
    l_c = round(l_c * 100) / 100;

    printf("%.2lf %.2lf %.2lf", l_a, l_b, l_c);
return 0;
}
