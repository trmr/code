#include <cstdio>
#include <algorithm>


const int MAX_N = 100;
const int MAX_W = 100;


int dp[MAX_N + 1][MAX_W + 1];

int N, W;
int w[MAX_N], v[MAX_N];

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[N][W]);
}

int main(){
    scanf("%d\n", &N);
    scanf("%d\n", &W);
    for (int i = 0; i < N; i++) {
        scanf("%d,%d\n", &w[i], &v[i]);
    }
    solve();
}