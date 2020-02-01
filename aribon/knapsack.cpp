#include <algorithm>
#include <cstdio>

const int MAX_N = 100;

int n, W;
int w[MAX_N], v[MAX_N];

int rec(int i, int j) {
    int res;
    if (i == n) {
        res = 0;
    }else if (j < w[i]) {
        res = rec(i + 1, j);
    } else {
        res = std::max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return res;
}

void solve() {
    printf("%d\n", rec(0, W));
}

int main(void) {
    scanf("%d", &n);
    scanf("%d", &W);
    for (int i = 0; i < n; i++) {
        scanf("%d,%d", &w[i], &v[i]);
    }
    solve();
}