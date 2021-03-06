#include <cstdio>
#include <algorithm>
#include <cstring>


const int MAX_N = 100;
const int MAX_K = 100000;

int n;
int K;

int a[MAX_N];
int m[MAX_N];

bool dp[MAX_K + 1];

void solve() {
    std::memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= K; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] -1;
            }
        }
    }
    if (dp[K] >= 0) printf("Yes\n");
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