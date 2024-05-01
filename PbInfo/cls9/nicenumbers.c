#include <stdio.h>
#include <string.h>

int main() {
    int N, numar, cnt = 0;
    char buffer[11];

    if (scanf("%d", &N) != 1) return 1;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &numar) != 1) return 1;

        sprintf(buffer, "%d", numar);
        if (strstr(buffer, "69") != NULL) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
