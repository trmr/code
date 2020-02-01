#include <cstdio>
#include <algorithm>


const int MAX_N = 100;
const int MAX_V = 100;
const int INF = 100000000;


int dp[MAX_N + 1][MAX_V + 1];

int N, W;
int w[MAX_N], v[MAX_N];

void solve() {
    std::fill(dp[0], dp[0] + MAX_N*MAX_V + 1, INF);
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= MAX_N*MAX_V; j++) {
            if (j < v[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = std::min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= MAX_N*MAX_V; i++) {
        if (dp[N][i] <= W) res = i;
    }
    printf("%d\n", res);
}

int main(){
    scanf("%d\n", &N);
    scanf("%d\n", &W);
    for (int i = 0; i < N; i++) {
        scanf("%d,%d\n", &w[i], &v[i]);
    }
    solve();
}