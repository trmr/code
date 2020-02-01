#include <cstdio>
#include <algorithm>


const int MAX_N = 100;
const int MAX_K = 100000;

int n;
int K;

int a[MAX_N];
int m[MAX_N];

bool dp[MAX_N + 1][MAX_K + 1];

void solve() {
    dp[0][0] = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= m[i]; k++){
                dp[i + 1][j] |= dp[i][j - k*a[i]];
            }
        }
    }
    if (dp[n][K]) printf("Yes\n");
    else printf("No\n");
}

int main(){
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d,%d", &a[i], &m[i]);
    }
    scanf("%d", &K);
    solve();
}