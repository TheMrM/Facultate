#include <stdio.h>

int nrCifre(int x) {
    if (x <= 9) return 1;
    if (x <= 99) return 2;
    if (x <= 999) return 3;
    if (x <= 9999) return 4;
    if (x <= 99999) return 5;
    if (x <= 999999) return 6;
    return -1;

}

int main() {
    int n, i;
    if ((scanf("%d", &n) != 1)) return 1;
    printf("%d", n);

    int numarCifre = nrCifre(n);
    if (numarCifre == -1) return 1;

    for (i = numarCifre; i < n; ++i) {
        printf("0");
    }
    
    printf("\n");
    return 0;
}

