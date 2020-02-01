#include <algorithm>
#include <cstdio>

const int MAX_N = 100;

int n, m;
char s[MAX_N], t[MAX_N];

int dp[MAX_N + 1][MAX_N + 1];

void solve() {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main() {
    scanf("%d\n", &n);
    scanf("%d\n", &m);
    for (int i = 0; i < n; i++) {
        scanf("%c\n", &s[i]);
    }
    for (int j = 0; j < m; j++) {
        scanf("%c\n", &t[j]);
    }
    solve();
    return 0;
}