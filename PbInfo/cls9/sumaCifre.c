#include <stdio.h>

int main() {
    long long n;
    int sum = 0;
    if (scanf("%lld", &n) != 1) return 1;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }        

    printf("%d", sum);
    return 0;
}
