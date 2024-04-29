#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>


int main() {
    float AB, BC, AC, cos_h1, cos_h2, cos_h3, h1, h2, h3;
    // Convertim unghiurile din grade in radiani
    const float rad = 180 / M_PI;

    // Citim laturile triunghiului
    if (scanf("%f %f %f", &AB, &BC, &AC) != 3) {
        fprintf(stderr, "Nu ati introdus 3 valori\n");
        return -1;
    }

    // Verificam daca se poate forma un triunghi
    if ((AB + BC > AC) && (BC + AC > AB) && (AB + AC > BC)) {
        // Calculam cosinusurile unghiurilor folosind formula cosinusului
        cos_h1 = (AC * AC + AB * AB - BC * BC) / (2 * AC * AB);
        cos_h2 = (AB * AB + BC * BC - AC * AC) / (2 * AB * BC);
        cos_h3 = (BC * BC + AC * AC - AB * AB) / (2 * BC * AC);

        // Convertim cosinusurile in unghiuri de grade
        h1 = rad * acos(cos_h1);
        h2 = rad * acos(cos_h2);
        h3 = rad * acos(cos_h3);

        // Afisam unghiurile cu 2 zecimale
        printf("%.2f %.2f %.2f\n", h1, h2, h3);
    } else {
        printf("Imposibil\n");
    }


    return 0;
}
