#include <algorithm>
#include <iostream>

const int MAX_N = 1000;
const int INF = 100000000;


int n;
int a[MAX_N];
int dp[MAX_N];

void solve() {
    std::fill(dp, dp + n, INF);
    for (int i = 0; i < n; i++) {
        *std::lower_bound(dp, dp + n, a[i]) = a[i];
    }
    printf("%d\n", std::lower_bound(dp, dp + n, INF) - dp);
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &a[i]);
    }
    solve();

}