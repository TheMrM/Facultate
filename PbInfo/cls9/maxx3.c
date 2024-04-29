#include <stdio.h>

int main() {
    char n[4];
    char m[4];
    if (scanf("%s %s", n, m) != 2) return 1;;

    int max_sute, max_zeci, max_unit;

    if (n[0] > m[0]) {
        max_sute = (n[0] - '0') * 10 + (m[0] - '0');
    } else {
        max_sute = (m[0] - '0') * 10 + (n[0] - '0');
    }

    if (n[1] > m[1]) {
        max_zeci = (n[1] - '0') * 10 + (m[1] - '0');
    } else {
        max_zeci = (m[1] - '0') * 10 + (n[1] - '0');
    }

    if (n[2] > m[2]) {
        max_unit = (n[2] - '0') * 10 + (m[2] - '0');
    } else {
        max_unit = (m[2] - '0') * 10 + (n[2] - '0');
    }

    printf("%d %d %d\n", max_sute, max_zeci, max_unit);

    return 0;
}
