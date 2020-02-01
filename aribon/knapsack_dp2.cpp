#include <algorithm>
#include <cstdio>
#include <cstring>


const int MAX_N = 100;

int dp[MAX_N + 1][MAX_N + 1];


int n, W;
int w[MAX_N], v[MAX_N];

void solve() {
//    std::memset(dp, -1, sizeof(dp));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[0][W]);
}

int main(void) {
    scanf("%d", &n);
    scanf("%d", &W);
    for (int i = 0; i < n; i++) {
        scanf("%d,%d", &w[i], &v[i]);
    }
    solve();
}