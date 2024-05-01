#include <stdio.h>

int main() {
    long long n;
    long long S = 0;
    if (scanf("%lld", &n) != 1) return 1;

    if (n < 0) return 1; 

    char str[20];
    sprintf(str, "%lld", n);
    
    long long prefix = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        prefix = prefix * 10 + (str[i] - '0');
        if (prefix % 2 == 0) {
            S += prefix;
        }
    }

    printf("%lld\n", S);

    return 0;
}
