#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* s) {
    long num = 0;
    int sign = 1;
    int i = 0;

    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');
        i++;

        if (num * sign > INT_MAX) {
            return INT_MAX;
        } else if (num * sign < INT_MIN) {
            return INT_MIN;
        }
    }

    num *= sign;

    return (int)num;
}

int main() {
    char s[100];
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = 0;

    int result = myAtoi(s);
    printf("%d\n", result);


    return 0;
}
