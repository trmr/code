#include <cstdio>
#include <algorithm>

const int V[6] = {1, 5, 10, 50, 100, 500};

//input
int C[6];
int A;

void solve() {
    int ans = 0;

    for (int i = 5; i >= 0; i--) {
        int t = std::min(A / V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }
    printf("%d\n", ans);
}

int main() {
    for (int i = 0; i < 6; i++) {
        scanf("%d", &C[i]);
    }
    scanf("%d", &A);

    solve();

    return 0;
}