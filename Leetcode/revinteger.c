#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int reverseNumber = 0;

    while (x != 0) {
        int digit = x % 10;
        x = x / 10;

        if (reverseNumber > INT_MAX / 10 || (reverseNumber == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return 0;
        }
        if (reverseNumber < INT_MIN / 10 || (reverseNumber == INT_MIN / 10 && digit < INT_MIN % 10)) {
            return 0;
        }
    reverseNumber = reverseNumber * 10 + digit;
    }
    return reverseNumber;
}

int main() {
    int n;

    if ((scanf("%d", &n) != 1)) return 1;
    int reversed = reverse(n);
    printf("%d", reversed);
    return 0;
}
