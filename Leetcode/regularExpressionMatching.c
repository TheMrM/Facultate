#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dp[21][31];

bool func(int i, int j, const char* s, const char* p) {
    if (dp[i][j] != -1) return dp[i][j];
    int s_len = strlen(s);
    int p_len = strlen(p);

    if (i >= s_len) {
        if (j == p_len) return dp[i][j] = true;
        if (j + 1 < p_len && p[j + 1] == '*') return dp[i][j] = func(i, j + 2, s, p);
        return dp[i][j] = false;
    } else if (j >= p_len) {
        return dp[i][j] = false;
    }

    bool match = (s[i] == p[j] || p[j] == '.');
    bool ans = false;

    if (match) {
        if (j + 1 < p_len && p[j + 1] == '*') ans = func(i + 1, j, s, p);
        if (!ans) ans = func(i + 1, j + 1, s, p);
    }
    if (!ans && j + 1 < p_len && p[j + 1] == '*') ans = func(i, j + 2, s, p);

    return dp[i][j] = ans;
}

bool isMatch(char* s, char* p) {
    memset(dp, -1, sizeof(dp));
    return func(0, 0, s, p);
}
int main() {
    
    const char* s = "ab";
    const char* p = ".*";

    printf("Result: %s\n", isMatch(s, p) ? "true" : "false");

    return 0;
}
