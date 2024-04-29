#include <stdio.h>
#include <math.h>

int main() {
    double AB, BC, AC, p, A, hA, hB, hC;

    // Citirea laturilor triunghiului
    if (scanf("%lf %lf %lf", &AB, &BC, &AC) != 3) {
        return -1;
    }

    // Verificam daca laturile citite sunt valide
    if (AB + BC >= AC && BC + AC >= AB && AC + AB >= BC) {
        // Calculam semiperimetrul triunghiului
        p = (AB + BC + AC) / 2;

        // Calculam aria triunghiului
        A = sqrt(p * (p - AB) * (p - BC) * (p - AC));

        // Calculam inaltimile triunghiului
        hA = (2 * A) / AB;
        hB = (2 * A) / BC;
        hC = (2 * A) / AC;

        // Convertim inaltimile la valori cu doua zecimale
        int h1 = (int)(hA * 100);
        int h2 = (int)(hB * 100);
        int h3 = (int)(hC * 100);

        // Afisam inaltimile triunghiului
        printf("%d.%02d ", h1 / 100, h1 % 100);
        printf("%d.%02d ", h2 / 100, h2 % 100);
        printf("%d.%02d\n", h3 / 100, h3 % 100);
    } else {
        // Afisam mesajul de eroare
        printf("Imposibil\n");
    }

return 0;
}
