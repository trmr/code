#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    COMinit();

    int ans1=0, ans2=0;

    if (n < 2) ans1 = 0;
    else {
        ans1 = COM(n, 2);
    }
    if (m < 2) ans2 = 0;
    else {
        ans2 = COM(m, 2);
    }

    cout << ans1 + ans2 << endl;

    return 0;
}