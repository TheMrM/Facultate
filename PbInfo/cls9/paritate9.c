#include <stdio.h>

int main() {
    char n[3], m[3];
    if (scanf("%s %s", n, m) != 2) return 1;

    int num_n = (n[0] -'0') * 10 + (n[1] - '0');
    int num_m = (m[0] -'0') * 10 + (m[1] - '0');

    if ((num_n % 2 == 0 && num_m % 2 == 0) || (num_n % 2 != 0 && num_m % 2 != 0)) {
        int sum = (n[0] - '0') + (n[1] - '0') + (m[0] - '0') + (m[1] - '0');
        printf("%d\n", sum);
    } else {
        int prod = (n[0] - '0') * (n[1] - '0') * (m[0] - '0') * (m[1] - '0');
        printf("%d\n", prod);
    }

    return 0;
}
