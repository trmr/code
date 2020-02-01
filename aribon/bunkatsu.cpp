#include <cstdio>

const int MAX_N = 1000;
const int MAX_M = 10000;

int n, m, M;

int dp[MAX_M + 1][MAX_N + 1];

void solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >= 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
            } else {
                dp[i][j] = dp[i - 1][j] % M;
            }
        }
    }
    printf("%d\n", dp[m][n]);
}

int main() {
    scanf("%d\n", &n);
    scanf("%d\n", &m);
    scanf("%d\n", &M);
    solve();
    return 0;
}