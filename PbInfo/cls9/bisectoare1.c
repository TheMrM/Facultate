#include <stdio.h>
#include <math.h>

int main() {

    double a, b, c, p;

    // Citirea coeficientilor triunghiului
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        return 1;
    }

    // Verificam daca pot forma un triunghi
    if (a + b >= c && b + c >= a && a + c >= b) {
        // Calculam semiperimetrul
        p = (a + b + c) / 2;

        // Calculam lungimile bisectoarelor
        double bA = sqrt((4 * b * c) / ((b + c) * (b + c)) * p * (p - a));
        double bB = sqrt((4 * a * c) / ((a + c) * (a + c)) * p * (p - b));
        double bC = sqrt((4 * a * b) / ((a + b) * (a + b)) * p * (p - c));

        // Convertim in intregi dupa multiplicare cu 100 ca sa trunchiem inloc sa rotunjim
        int b1 = (int) (bA * 100);
        int b2 = (int) (bB * 100);
        int b3 = (int) (bC * 100);

        // Afisam bisectoarele cu 2 zecimale
        printf("%d.%d%d ", b1 / 100, (b1 / 10) % 10, b1 % 10);
        printf("%d.%d%d ", b2 / 100, (b2 / 10) % 10, b2 % 10);
        printf("%d.%d%d\n", b3 / 100, (b3 / 10) % 10, b3 % 10);
    } else {
        printf("Imposibil\n");
    }

    return 0;
}
