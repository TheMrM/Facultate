#include <stdio.h>

int main() {
    int n, k, num, firstDigit, sum = 0, validNumFound = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        firstDigit = num;
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }

        if (firstDigit == k) {
            validNumFound = 1;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
        }
    }

    if (validNumFound) {
        printf("%d\n", sum);
    } else {
        return 1;
    }


    return 0;
}
