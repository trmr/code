#include <cstdio>

const int MAX_n = 1000;
const int MAX_m = 1000;
const int MAX_M = 10000;
const int M = 10000;

int n, m;
int a[MAX_n];

int dp[MAX_n + 1][MAX_m + 1];

void solve() {
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j - 1 - a[i] >= 0) {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
            } else {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main() {
    scanf("%d\n", &n);
    scanf("%d\n", &m);
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &a[i]);
    }
    solve();
}